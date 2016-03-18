﻿namespace com.mtaulty.OxfordVerify
{
  using Accounts;
  using com.mtaulty.OxfordVerify.Audio;
  using com.mtaulty.OxfordVerify.RestApi;
  using System;
  using System.Collections.Generic;
  using System.Linq;
  using System.Threading.Tasks;
  using Windows.Storage;
  using Windows.Storage.Streams;
  public class OxfordVerificationClient
  {
    public OxfordVerificationClient(string oxfordKey)
    {
      this.restClient = new RestClient(oxfordKey);
      this.audioRecorder = new AudioRecorder();
    }
    public async Task<List<string>> GetUsersAsync()
    {
      var result = await AccountMap.GetUserNamesAsync();
      return (result);
    }
    public async Task<string> GetVerificationPhraseForUserAsync(string user)
    {
      string phrase = string.Empty;

      if (this.verificationPhrases == null)
      {
        var phrases = await this.restClient.GetVerificationPhrasesAsync();

        if (phrases != null)
        {
          this.verificationPhrases = phrases.Select(p => p.Phrase).ToList();
        }
      }

      if (this.verificationPhrases != null)
      {
        phrase = this.verificationPhrases[
          user.Length % this.verificationPhrases.Count];
      }
      return (phrase);
    }
    public async Task<EnrollmentResult> RecordAndEnrollUserAsync(
      string user, TimeSpan recordingTime)
    {
      EnrollmentResult result = null;

      Guid? accountGuid = await AccountMap.GetGuidForUserNameAsync(user);

      if (accountGuid == null)
      {
        var profile = await this.restClient.AddVerificationProfileAsync();
        accountGuid = profile.VerificationProfileId;
        await AccountMap.SetGuidForUserNameAsync(user, accountGuid.Value);
      }
      using (var recordedStream = await this.RecordSpeechToFileAsync(recordingTime))
      {
        result = await this.restClient.EnrollAsync(accountGuid.Value, recordedStream);
      }
      return (result);
    }
    public async Task<VerificationResult> RecordAndVerifyUserAsync(
      string user, TimeSpan recordingTime)
    {
      VerificationResult result = null;

      Guid? accountGuid = await AccountMap.GetGuidForUserNameAsync(user);

      if (!accountGuid.HasValue)
      {
        throw new ArgumentException($"user name {user} is not recognised");
      }
      using (var recordedStream = await this.RecordSpeechToFileAsync(recordingTime))
      {
        result = await this.restClient.VerifyAsync(
          accountGuid.Value, recordedStream);
      }
      return (result);
    }
    async Task CreateStorageFileAsync()
    {
      this.temporaryFile =
        await ApplicationData.Current.TemporaryFolder.CreateFileAsync(
          TEMPORARY_FILE_NAME,
          CreationCollisionOption.ReplaceExisting);
    }
    async Task<IInputStream> RecordSpeechToFileAsync(TimeSpan recordingTime)
    {
      await this.CreateStorageFileAsync();

      await this.audioRecorder.StartRecordToFileAsync(this.temporaryFile);

      await Task.Delay(recordingTime);

      await this.audioRecorder.StopRecordAsync();

      var stream = await this.temporaryFile.OpenReadAsync();

      return (stream);
    }
    StorageFile temporaryFile;
    List<string> verificationPhrases;
    AudioRecorder audioRecorder;
    RestClient restClient;

    static readonly string TEMPORARY_FILE_NAME = "recording.bin";
  }
}