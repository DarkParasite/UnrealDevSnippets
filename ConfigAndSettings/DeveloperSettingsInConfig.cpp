/*
* This snipper is about how to have custom developer settings that can be set in Config/DefaultGame.ini 
*/

// STEP 1 : First create a class derived from UDeveloperSettings

/*
* PREPROCESSOR PARAMS
* Config - Game(Modify the Config/DefaultGame.ini), MyCustomConfig(For custom config files, not sure if works properly in all builds)
* DefaultConfig - Add this if use Config=Game
* Blueprintable, BlueprintType - Add this if you want the settings to be exposed to blueprint
*/

UCLASS(Config=Game, DefaultConfig,  Blueprintable, BlueprintType)
class MULTIPLAYERSHOOTER_API UMultiplayerSessionsDevSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:

  // Config Keyword is important
	UPROPERTY(Config, EditDefaultsOnly, BlueprintReadOnly)
	uint8 MaxPlayerInSession;

	UPROPERTY(Config, EditDefaultsOnly, BlueprintReadOnly)
	uint8 MaxTeamCount;
	
};

// STEP 2 : Set the value in the DefaultGame.ini file

/*
* Syntax :
* [/Script/ProjectName.ClassNameWithout(A)(U)Prefix]
*
[/Script/MultiplayerShooter.MultiplayerSessionsDevSettings]
MaxPlayerInSession = 100 
MaxTeamCount = 35
*/

// STEP 3 : Getting the values

 // Load the MaxPlayer from the config file
if (const UMultiplayerSessionsDevSettings* MultiplayerSessionsDevSettings = GetDefault<UMultiplayerSessionsDevSettings>())
{
	MaxPlayersInSession = MultiplayerSessionsDevSettings->MaxPlayers;
  MaxTeams = MultiplayerSessionsDevSettings->MaxTeamCount;
} 


/*
* NOTE : 
* Its is also possible to set initial values for actors and other entities. Refer the following resources to understand more on this topic
* https://forums.unrealengine.com/t/how-to-store-variables-to-a-custom-ini-file/330274/6
* https://www.tomlooman.com/unreal-engine-developer-settings/
*
*/

  
