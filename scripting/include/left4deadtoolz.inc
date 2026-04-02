#if defined _left4deadtoolz_included
 #endinput
#endif
#define _left4deadtoolz_included

// ====================================================================================================
// FORWARDS
// ====================================================================================================
/**
 * @brief Called whenever ZombieManager::SpawnSpecial(ZombieClassType,Vector&,QAngle&) is invoked
 * @remarks Only used for bot special spawns (not players)
 * @remarks zombieClass: 1=Smoker, 2=Boomer, 3=Hunter, 4=Spitter, 5=Jockey, 6=Charger
 *
 * @param zombieClass	Zombie class that will be spawned
 * @param vecPos		Vector coordinate where special will be spawned
 * @param vecAng		QAngle where special will be facing
 *
 * @return				Plugin_Handled to block special from spawning,
 * 						Plugin_Changed to change the zombie class type to spawn, Plugin_Continue otherwise
 */
forward Action OnSpawnSpecial(int &zombieClass, const float vecPos[3], const float vecAng[3]);

/**
 * @brief Called whenever ZombieManager::SpawnSpecial(ZombieClassType,Vector&,QAngle&) is invoked
 * @remarks Only used for bot special spawns (not players)
 * @remarks zombieClass: 1=Smoker, 2=Boomer, 3=Hunter, 4=Spitter, 5=Jockey, 6=Charger
 * @remarks This forward will not trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param client		The client index who spawned. Can be 0 if spawning failed
 * @param zombieClass	Zombie class that will be spawned
 * @param vecPos		Vector coordinate where special will be spawned
 * @param vecAng		QAngle where special will be facing
 *
 * @noreturn
 */
forward void OnSpawnSpecial_Post(int client, int zombieClass, const float vecPos[3], const float vecAng[3]);

/**
 * @brief Called whenever ZombieManager::SpawnSpecial(ZombieClassType,Vector&,QAngle&) is invoked
 * @remarks Only used for bot special spawns (not players)
 * @remarks zombieClass: 1=Smoker, 2=Boomer, 3=Hunter, 4=Spitter, 5=Jockey, 6=Charger
 * @remarks This forward will ONLY trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param client		The client index who spawned. Can be 0 if spawning failed or -1 if blocked
 * @param zombieClass	Zombie class that will be spawned
 * @param vecPos		Vector coordinate where special will be spawned
 * @param vecAng		QAngle where special will be facing
 *
 * @noreturn
 */
forward void OnSpawnSpecial_PostHandled(int client, int zombieClass, const float vecPos[3], const float vecAng[3]);

/**
 * @brief Called whenever ZombieManager::SpawnTank(Vector&,QAngle&) is invoked
 * @remarks Not invoked if z_spawn tank is used and it gives a ghosted/dead player tank
 * @remarks This sometimes triggers every frame or so, in L4D2 "c7m3_port" map on Windows, after leaving the saferoom in Versus
 *
 * @param vecPos		Vector coordinate where tank is spawned
 * @param vecAng		QAngle where tank will be facing
 *
 * @return				Plugin_Handled to block tank from spawning, Plugin_Continue otherwise
 */
forward Action OnSpawnTank(const float vecPos[3], const float vecAng[3]);

/**
 * @brief Called whenever ZombieManager::SpawnTank(Vector&,QAngle&) is invoked
 * @remarks Not invoked if z_spawn tank is used and it gives a ghosted/dead player tank
 * @remarks This forward will not trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 * @remarks This sometimes triggers every frame or so, in L4D2 "c7m3_port" map on Windows, after leaving the saferoom in Versus, client index will be -1
 *
 * @param client		The client index who spawned
 * @param vecPos		Vector coordinate where tank is spawned
 * @param vecAng		QAngle where tank will be facing
 *
 * @noreturn
 */
forward void OnSpawnTank_Post(int client, const float vecPos[3], const float vecAng[3]);

/**
 * @brief Called whenever ZombieManager::SpawnTank(Vector&,QAngle&) is invoked
 * @remarks Not invoked if z_spawn tank is used and it gives a ghosted/dead player tank
 * @remarks This forward will ONLY trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param client		The client index who spawned (can be -1 if blocked in pre hook)
 * @param vecPos		Vector coordinate where tank is spawned
 * @param vecAng		QAngle where tank will be facing
 *
 * @noreturn
 */
forward void OnSpawnTank_PostHandled(int client, const float vecPos[3], const float vecAng[3]);

/**
 * @brief Called whenever ZombieManager::SpawnWitch(Vector&,QAngle&) is invoked
 * @brief Called when a Witch spawns
 *
 * @param vecPos		Vector coordinate where witch is spawned
 * @param vecAng		QAngle where witch will be facing
 *
 * @return 				Plugin_Handled to block witch from spawning, Plugin_Continue otherwise
 */
forward Action OnSpawnWitch(const float vecPos[3], const float vecAng[3]);

/**
 * @brief Called whenever ZombieManager::SpawnWitch(Vector&,QAngle&) is invoked
 * @brief Called when a Witch spawns
 * @remarks This forward will not trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param entity		Entity index that spawned
 * @param vecPos		Vector coordinate where witch is spawned
 * @param vecAng		QAngle where witch will be facing
 *
 * @noreturn
 */
forward void OnSpawnWitch_Post(int entity, const float vecPos[3], const float vecAng[3]);

/**
 * @brief Called whenever ZombieManager::SpawnWitch(Vector&,QAngle&) is invoked
 * @brief Called when a Witch spawns
 * @remarks This forward will ONLY trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param entity		Entity index that spawned (can be -1 if blocked)
 * @param vecPos		Vector coordinate where witch is spawned
 * @param vecAng		QAngle where witch will be facing
 *
 * @noreturn
 */
forward void OnSpawnWitch_PostHandled(int entity, const float vecPos[3], const float vecAng[3]);

/**
 * @brief Called whenever ZombieManager::SpawnWitchBride(Vector&,QAngle&) is invoked
 * @brief Called when a Witch Bride spawns
 *
 * @param vecPos		Vector coordinate where witch is spawned
 * @param vecAng		QAngle where witch will be facing
 *
 * @return 				Plugin_Handled to block witch from spawning, Plugin_Continue otherwise
 */
forward Action OnSpawnWitchBride(const float vecPos[3], const float vecAng[3]);

/**
 * @brief Called whenever ZombieManager::SpawnWitchBride(Vector&,QAngle&) is invoked
 * @brief Called when a Witch Bride spawns
 * @remarks This forward will not trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param entity		Entity index that spawned
 * @param vecPos		Vector coordinate where witch is spawned
 * @param vecAng		QAngle where witch will be facing
 *
 * @noreturn
 */
forward void OnSpawnWitchBride_Post(int entity, const float vecPos[3], const float vecAng[3]);

/**
 * @brief Called whenever ZombieManager::SpawnWitchBride(Vector&,QAngle&) is invoked
 * @brief Called when a Witch Bride spawns
 * @remarks This forward will ONLY trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param entity		Entity index that spawned (can be -1 if blocked)
 * @param vecPos		Vector coordinate where witch is spawned
 * @param vecAng		QAngle where witch will be facing
 *
 * @noreturn
 */
forward void OnSpawnWitchBride_PostHandled(int entity, const float vecPos[3], const float vecAng[3]);

/**
 * @brief Called whenever CDirector::OnMobRushStart(void) is invoked
 * @remarks called on random hordes, mini and finale hordes, and boomer hordes, causes Zombies to attack
 *			Not called on "z_spawn mob", hook the console command and check arguments to catch plugin mobs
 *			This function is used to reset the Director's natural horde timer
 *
 * @return				Plugin_Handled to block, Plugin_Continue otherwise
 */
forward Action OnMobRushStart();

/**
 * @brief Called whenever CDirector::OnMobRushStart(void) is invoked
 * @remarks called on random hordes, mini and finale hordes, and boomer hordes, causes Zombies to attack
 *			Not called on "z_spawn mob", hook the console command and check arguments to catch plugin mobs
 *			This function is used to reset the Director's natural horde timer
 * @remarks This forward will not trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @noreturn
 */
forward void OnMobRushStart_Post();

/**
 * @brief Called whenever CDirector::OnMobRushStart(void) is invoked
 * @remarks called on random hordes, mini and finale hordes, and boomer hordes, causes Zombies to attack
 *			Not called on "z_spawn mob", hook the console command and check arguments to catch plugin mobs
 *			This function is used to reset the Director's natural horde timer
 * @remarks This forward will ONLY trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @noreturn
 */
forward void OnMobRushStart_PostHandled();

/**
 * @brief Called whenever ZombieManager::SpawnITMob(int) is invoked
 * @remarks called on boomer hordes, increases Zombie Spawn Queue
 *
 * @param amount		Amount of Zombies to add to Queue
 *
 * @return				Plugin_Handled to block, Plugin_Changed to use overwritten values from plugin, Plugin_Continue otherwise
 */
forward Action OnSpawnITMob(int &amount);

/**
 * @brief Called whenever ZombieManager::SpawnITMob(int) is invoked
 * @remarks called on boomer hordes, increases Zombie Spawn Queue
 * @remarks This forward will not trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param amount		Amount of Zombies to add to Queue
 *
 * @noreturn
 */
forward void OnSpawnITMob_Post(int amount);

/**
 * @brief Called whenever ZombieManager::SpawnITMob(int) is invoked
 * @remarks called on boomer hordes, increases Zombie Spawn Queue
 * @remarks This forward will ONLY trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param amount		Amount of Zombies to add to Queue
 *
 * @noreturn
 */
forward void OnSpawnITMob_PostHandled(int amount);

/**
 * @brief Called whenever ZombieManager::SpawnMob(int) is invoked
 * @remarks called on natural hordes & z_spawn mob, increases Zombie Spawn
 *			Queue, triggers player OnMobSpawned (vocalizations), sets horde
 *			direction, and plays horde music
 *
 * @param amount		Amount of Zombies to add to Queue
 *
 * @return				Plugin_Handled to block, Plugin_Changed to use overwritten values from plugin, Plugin_Continue otherwise
 */
forward Action OnSpawnMob(int &amount);

/**
 * @brief Called whenever ZombieManager::SpawnMob(int) is invoked
 * @remarks called on natural hordes & z_spawn mob, increases Zombie Spawn
 *			Queue, triggers player OnMobSpawned (vocalizations), sets horde
 *			direction, and plays horde music
 * @remarks This forward will not trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param amount		Amount of Zombies to add to Queue
 *
 * @noreturn
 */
forward void OnSpawnMob_Post(int amount);

/**
 * @brief Called whenever ZombieManager::SpawnMob(int) is invoked
 * @remarks called on natural hordes & z_spawn mob, increases Zombie Spawn
 *			Queue, triggers player OnMobSpawned (vocalizations), sets horde
 *			direction, and plays horde music
 * @remarks This forward will ONLY trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param amount		Amount of Zombies to add to Queue
 *
 * @noreturn
 */
forward void OnSpawnMob_PostHandled(int amount);

/**
 * @brief Called when a witch has been startled by someone
 *
 * @param witch			The witch entity index
 * @param victim		Client who harassed the Witch, will be 0 on spawn
 *
 * @noreturn
 **/
forward void OnWitchSetHarasser(int witch, int victim);

/**
 * @brief Called when Tank::EnterStasis() is invoked
 * @remarks Called when a Tank enters stasis mode in Versus mode
 *
 * @param tank			Client index of the Tank
 *
 * @noreturn
 **/
forward void OnEnterStasis(int tank);

/**
 * @brief Called when Tank::LeaveStasis() is invoked
 * @remarks Called when a Tank leaves stasis mode in Versus mode
 *
 * @param tank				Client index of the Tank
 *
 * @noreturn
 **/
forward void OnLeaveStasis(int tank);

/**
 * @brief Called whenever CTerrorPlayer::OnEnterGhostState(CTerrorPlayer*) is invoked
 * @remarks This happens when a player enters ghost mode (or in finales auto-materialized)
 * @remarks This forward triggers before the player enters ghost state allowing it to be blocked
 *
 * @param client		the client that has entered ghost mode
 *
 * @return				Plugin_Handled to block, Plugin_Continue otherwise
 */
forward Action OnEnterGhostState(int client);

/**
 * @brief Called whenever CTerrorPlayer::OnEnterGhostState(CTerrorPlayer*) is invoked
 * @remarks This happens when a player enters ghost mode (or in finales auto-materialized)
 * @remarks This forward will not trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param client		the client that has entered ghost mode
 *
 * @noreturn
 */
forward void OnEnterGhostState_Post(int client);

/**
 * @brief Called whenever CTerrorPlayer::OnEnterGhostState(CTerrorPlayer*) is invoked
 * @remarks This happens when a player enters ghost mode (or in finales auto-materialized)
 * @remarks This forward will ONLY trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param client		the client that has entered ghost mode
 *
 * @noreturn
 */
forward void OnEnterGhostState_PostHandled(int client);

/**
 * @brief Called whenever CTerrorPlayer::TakeOverBot(CTerrorPlayer*) is invoked
 * @remarks This happens when player is looking to take over a bot
 *
 * @param client			the client that is looking to take over a bot
 *
 * @return					Plugin_Handled to block, Plugin_Continue otherwise
 */
forward Action OnTakeOverBot(int client);

/**
 * @brief Called whenever CTerrorPlayer::TakeOverBot(CTerrorPlayer*) is invoked
 * @remarks This happens when player is looking to take over a bot
 * @remarks This forward will not trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param client			the client that is looking to take over a bot
 * @param success			true if the takeover was successful, false otherwise
 *
 * @noreturn
 */
forward void OnTakeOverBot_Post(int client, bool success);

/**
 * @brief Called whenever CTerrorPlayer::TakeOverBot(CTerrorPlayer*) is invoked
 * @remarks This happens when player is looking to take over a bot
 * @remarks This forward will ONLY trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param client			the client that is looking to take over a bot
 * @param success			true if the takeover was successful, false otherwise
 *
 * @noreturn
 */
forward void OnTakeOverBot_PostHandled(int client, bool success);

/**
 * @brief Called whenever CTerrorPlayer::MaterializeFromGhost is invoked
 * @remarks Called when a Special Infected spawns out of ghost mode
 *
 * @param victim			the client who spawned
 *
 * @return					Plugin_Handled to block, Plugin_Continue otherwise
 */
forward Action OnMaterializeFromGhost(int client);

/**
 * @brief Called whenever CTerrorPlayer::MaterializeFromGhost is invoked
 * @remarks Called when a Special Infected spawns out of ghost mode
 * @remarks This forward will not trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param victim			the client who spawned
 *
 * @noreturn
 */
forward void OnMaterializeFromGhost_Post(int client);

/**
 * @brief Called whenever CTerrorPlayer::MaterializeFromGhost is invoked
 * @remarks Called when a Special Infected spawns out of ghost mode
 * @remarks This forward will ONLY trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param victim			the client who spawned
 *
 * @noreturn
 */
forward void OnMaterializeFromGhost_PostHandled(int client);

/**
 * @brief Called whenever CDirector::OnFinishIntro is invoked
 * @remarks called when the intro cutscene has finished
 * @remarks This is a post hook, it appears to be called before the "OnReleaseSurvivorPositions" forward
 *
 * @noreturn
 */
forward void OnFinishIntro();

/**
 * @brief Called whenever IsTeamFull is invoked
 * @remarks called when bots or players are joining a team
 *
 * @param team			Which team is being checked. 2=Survivors. 3=Special Infected
 *
 * @return				Plugin_Handled to block changing team, Plugin_Continue otherwise
 */
forward Action OnIsTeamFull(int team, bool &full);

/**
 * @brief Called whenever CTerrorGameRules::ClearTeamScores(bool) is invoked
 * @remarks 	This resets the map score at the beginning of a map, and by checking
 *			the campaign scores on a small timer you can see if they were reset as well
 *
 * @param newCampaign	if true then this is a new campaign, if false a new chapter. Not used for L4D1
 *
 * @return				Plugin_Handled to block scores from being cleared, Plugin_Continue otherwise. Does not block reset in L4D1
 */
forward Action OnClearTeamScores(bool newCampaign);

/**
 * @brief Called whenever CTerrorGameRules::SetCampaignScores(int,int) is invoked
 * @remarks The campaign scores are updated after the 2nd round is completed
 *
 * @param scoreA		score of logical team A
 * @param scoreB		score of logical team B
 *
 * @return				Plugin_Handled to block campaign scores from being set, Plugin_Continue otherwise
 */
forward Action OnSetCampaignScores(int &scoreA, int &scoreB);

/**
 * @brief Called whenever CTerrorGameRules::SetCampaignScores(int,int) is invoked
 * @remarks The campaign scores are updated after the 2nd round is completed
 *
 * @param scoreA		score of logical team A
 * @param scoreB		score of logical team B
 *
 * @noreturn
 */
forward void OnSetCampaignScores_Post(int scoreA, int scoreB);

/**
 * @brief Called whenever CDirector::OnFirstSurvivorLeftSafeArea is invoked
 * @remarks A versus round is started when survivors leave the safe room, or force started
 *			after 90 seconds regardless
 *
 * @param client		the survivor that left the safe area first
 *
 * @return				Plugin_Handled to block round from being started, Plugin_Continue otherwise
 */
forward Action OnFirstSurvivorLeftSafeArea(int client);

/**
 * @brief Called whenever CDirector::OnFirstSurvivorLeftSafeArea is invoked
 * @remarks A versus round is started when survivors leave the safe room, or force started
 *			after 90 seconds regardless
 * @remarks This forward will not trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param client		the survivor that left the safe area first
 *
 * @noreturn
 */
forward void OnFirstSurvivorLeftSafeArea_Post(int client);

/**
 * @brief Called whenever CDirector::OnFirstSurvivorLeftSafeArea is invoked
 * @remarks A versus round is started when survivors leave the safe room, or force started
 *			after 90 seconds regardless
 * @remarks This forward will ONLY trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param client		the survivor that left the safe area first
 *
 * @noreturn
 */
forward void OnFirstSurvivorLeftSafeArea_PostHandled(int client);

/**
 * @brief Called whenever CDirector::OnForceSurvivorPositions is invoked
 * @remarks Triggers after round start when Survivors are forced into starting positions, usually first map and finale escape start, does not trigger on all maps
 *
 * @noreturn
 */
forward void OnForceSurvivorPositions_Pre();

/**
 * @brief Called whenever CDirector::OnForceSurvivorPositions is invoked
 * @remarks Triggers after round start when Survivors are forced into starting positions, usually first map and finale escape start, does not trigger on all maps
 *
 * @noreturn
 */
forward void OnForceSurvivorPositions();

/**
 * @brief Called whenever CDirector::OnReleaseSurvivorPositions is invoked
 * @remarks Triggers after round start when Survivors are released from the starting positions, usually first map and finale escape start, does not trigger on all maps
 *
 * @noreturn
 */
forward void OnReleaseSurvivorPositions();

/**
 * @brief Called whenever "SpeakResponseConceptFromEntityIO" is invoked
 * @remarks Triggers on concept talking
 *
 * @param entity		Entity doing the talking (not always client indexes, might be a func_orator)
 *
 * @noreturn
 */
forward void OnSpeakResponseConcept_Pre(int entity);

/**
 * @brief Called whenever "SpeakResponseConceptFromEntityIO" is invoked
 * @remarks Triggers on concept talking
 *
 * @param entity		Entity doing the talking (not always client indexes, might be a func_orator)
 *
 * @noreturn
 */
forward void OnSpeakResponseConcept_Post(int entity);

/**
 * @brief Called whenever CTerrorPlayer::GetCrouchTopSpeed() is invoked
 * @remarks Constantly called to get players max Crouch speed
 *
 * @param target		the client that its being called on (not changeable)
 * @param retVal		what to override the return value with
 *
 * @return				Plugin_Handled to override return value, Plugin_Continue otherwise
 */
forward Action OnGetCrouchTopSpeed(int target, float &retVal);

/**
 * @brief Called whenever CTerrorPlayer::GetRunTopSpeed() is invoked
 * @remarks Constantly called to get players max Run speed
 *
 * @param target		the client that its being called on (not changeable)
 * @param retVal		what to override the return value with
 *
 * @return				Plugin_Handled to override return value, Plugin_Continue otherwise
 */
forward Action OnGetRunTopSpeed(int target, float &retVal);

/**
 * @brief Called whenever CTerrorPlayer::GetWalkTopSpeed() is invoked
 * @remarks Constantly called to get players max Walk speed
 *
 * @param target		the client that its being called on (not changeable)
 * @param retVal		what to override the return value with
 *
 * @return				Plugin_Handled to override return value, Plugin_Continue otherwise
 */
forward Action OnGetWalkTopSpeed(int target, float &retVal);

/**
 * @brief Called whenever CDirector::GetScriptValue(const char*, int) is invoked
 * @remarks A script value is map specific
 *
 * @param key			the script's key name
 * @param retVal		what to override the return value with
 *
 * @return				Plugin_Handled to override return value, Plugin_Continue otherwise
 */
forward Action OnGetScriptValueInt(const char[] key, int &retVal);

/**
 * @brief Called whenever CDirector::GetScriptValue(const char*, float) is invoked
 * @remarks A script value is map specific
 *
 * @param key			the script's key name
 * @param retVal		what to override the return value with
 *
 * @return				Plugin_Handled to override return value, Plugin_Continue otherwise
 */
forward Action OnGetScriptValueFloat(const char[] key, float &retVal);

/**
 * @brief Called whenever CTerrorGameRules::HasConfigurableDifficultySetting() is invoked
 * @remarks used to deny/allow difficulty changes in different game modes
 *
 * @param retVal		what to override the return value with. 1 to allow difficulty configuration, 0 to deny
 *
 * @return				Plugin_Handled to override return value, Plugin_Continue otherwise
 */
forward Action OnHasConfigurableDifficulty(int &retVal);

/**
 * @brief Called whenever CTerrorGameRules::HasConfigurableDifficultySetting() is invoked
 * @remarks used to deny/allow difficulty changes in different game modes
 *
 * @param retVal		what to override the return value with. 1 to allow difficulty configuration, 0 to deny
 *
 * @noreturn
 */
forward void OnHasConfigurableDifficulty_Post(int retVal);

/**
 * @brief Called whenever CTerrorGameRules::GetSurvivorSet(void) is invoked
 * @brief Changed the value will crash the server
 * @remarks Constantly called to get the survivor character set
 *
 * @param retVal		what to override the return value with
 *
 * @return				Plugin_Handled to override return value, Plugin_Continue otherwise
 */
forward Action OnGetSurvivorSet(int &retVal);

/**
 * @brief Called whenever CTerrorGameRules::FastGetSurvivorSet(void) is invoked
 * @brief Changed the value will crash the server
 * @remarks Constantly called to get the survivor character set
 *
 * @param retVal	what to override the return value with
 *
 * @return			Plugin_Handled to override return value, Plugin_Continue otherwise
 */
forward Action OnFastGetSurvivorSet(int &retVal);

/**
 * @brief Called whenever CDirectorVersusMode::GetMissionVersusBossSpawning() is invoked
 * @remarks Passed values are from the map's Mission Keyvalues. If those keyvalues don't exist, they are from cvar and other globals
 *
 * @param spawn_pos_min		Minimum spawn position (percent of flow distance) for bosses
 * @param spawn_pos_max		Maximum spawn position (percent of flow distance) for bosses
 * @param tank_chance		Chance for a tank to spawn on this map
 * @param witch_chance		Chance for a witch to spawn on this map
 *
 * @return			Plugin_Handled to block reading map data, Plugin_Changed to use overwritten values from plugin, Plugin_Continue to continue to read from mission data
 */
forward Action OnGetMissionVSBossSpawning(float &spawn_pos_min, float &spawn_pos_max, float &tank_chance, float &witch_chance);

/**
 * @brief Called whenever CDirectorVersusMode::GetMissionVersusBossSpawning() is invoked
 * @remarks Passed values are from the map's Mission Keyvalues. If those keyvalues don't exist, they are from cvar and other globals
 * @remarks This forward will not trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param spawn_pos_min		Minimum spawn position (percent of flow distance) for bosses
 * @param spawn_pos_max		Maximum spawn position (percent of flow distance) for bosses
 * @param tank_chance		Chance for a tank to spawn on this map
 * @param witch_chance		Chance for a witch to spawn on this map
 *
 * @noreturn
 */
forward void OnGetMissionVSBossSpawning_Post(float spawn_pos_min, float spawn_pos_max, float tank_chance, float witch_chance);

/**
 * @brief Called whenever CDirectorVersusMode::GetMissionVersusBossSpawning() is invoked
 * @remarks Passed values are from the map's Mission Keyvalues. If those keyvalues don't exist, they are from cvar and other globals
 * @remarks This forward will ONLY trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param spawn_pos_min		Minimum spawn position (percent of flow distance) for bosses
 * @param spawn_pos_max		Maximum spawn position (percent of flow distance) for bosses
 * @param tank_chance		Chance for a tank to spawn on this map
 * @param witch_chance		Chance for a witch to spawn on this map
 *
 * @noreturn
 */
forward void OnGetMissionVSBossSpawning_PostHandled(float spawn_pos_min, float spawn_pos_max, float tank_chance, float witch_chance);

/**
 * @brief Called whenever ZombieManager::ReplaceTank(CTerrorPlayer *,CTerrorPlayer *) is invoked
 * @remarks When a player loses tank control and is replaced by another player. Not invoked if tank is bot
 *
 * @param tank			the player who was a tank
 * @param newtank		a player who has become a new tank
 *
 * @return			Plugin_Handled to block tank from being replace, Plugin_Continue otherwise
 */
forward Action OnReplaceTank(int tank, int newtank);

/**
 * @brief Called whenever ZombieManager::ReplaceTank(CTerrorPlayer *,CTerrorPlayer *) is invoked
 * @remarks When a player loses tank control and is replaced by another player. Not invoked if tank is bot
 * @remarks This forward will not trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param tank			the player who was a tank
 * @param newtank		a player who has become a new tank
 *
 * @noreturn
 */
forward void OnReplaceTank_Post(int tank, int newtank);

/**
 * @brief Called whenever ZombieManager::ReplaceTank(CTerrorPlayer *,CTerrorPlayer *) is invoked
 * @remarks When a player loses tank control and is replaced by another player. Not invoked if tank is bot
 * @remarks This forward will ONLY trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 * 
 * @param tank			the player who was a tank
 * @param newtank		a player who has become a new tank
 *
 * @noreturn
 */
forward void OnReplaceTank_PostHandled(int tank, int newtank);

/**
 * @brief Called whenever CTankClaw::DoSwing(CTankClaw *this) is invoked
 * @remarks When a tank is swinging to punch
 *
 * @param tank			tank client index
 * @param claw			the claw entity index
 *
 * @noreturn
 */
forward void TankClaw_DoSwing_Pre(int tank, int claw);

/**
 * @brief Called whenever CTankClaw::DoSwing(CTankClaw *this) is invoked
 * @remarks When a tank is swinging to punch
 *
 * @param tank			tank client index
 * @param claw			the claw entity index
 *
 * @noreturn
 */
forward void TankClaw_DoSwing_Post(int tank, int claw);

/**
 * @brief Called whenever CTankClaw::GroundPound() is invoked
 * @remarks When hitting the ground (maybe only when hitting an incapped player)
 * @remarks The forwards "TankClaw_OnPlayerHit_Pre" and "TankClaw_OnPlayerHit_Post" trigger after this, allowing identification of victim
 * @remarks The forwards "TankClaw_DoSwing_Pre" and "TankClaw_DoSwing_Post" can trigger after this
 *
 * @param tank			tank client index
 * @param claw			the claw entity index
 *
 * @noreturn
 */
forward void TankClaw_GroundPound_Pre(int tank, int claw);

/**
 * @brief Called whenever CTankClaw::GroundPound() is invoked
 * @remarks When hitting the ground (maybe only when hitting an incapped player)
 * @remarks The forwards "TankClaw_OnPlayerHit_Pre" and "TankClaw_OnPlayerHit_Post" trigger before this
 * @remarks The forwards "TankClaw_DoSwing_Pre" and "TankClaw_DoSwing_Post" can trigger after this
 *
 * @param tank			tank client index
 * @param claw			the claw entity index
 *
 * @noreturn
 */
forward void TankClaw_GroundPound_Post(int tank, int claw);

/**
 * @brief Called whenever CTankClaw::OnPlayerHit(CTerrorPlayer*, bool) is invoked
 * @remarks When a tank swings and punches a player
 *
 * @param tank			tank client index
 * @param claw			the claw entity index
 * @param player		the player being hit
 *
 * @return				Plugin_Handled to block the target player from being stumbled, Plugin_Continue otherwise
 */
forward Action TankClaw_OnPlayerHit_Pre(int tank, int claw, int player);

/**
 * @brief Called whenever CTankClaw::OnPlayerHit(CTerrorPlayer*, bool) is invoked
 * @remarks When a tank swings and punches a player
 * @remarks This forward will not trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param tank			tank client index
 * @param claw			the claw entity index
 * @param player		the player being hit
 *
 * @noreturn
 */
forward void TankClaw_OnPlayerHit_Post(int tank, int claw, int player);

/**
 * @brief Called whenever CTankClaw::OnPlayerHit(CTerrorPlayer*, bool) is invoked
 * @remarks When a tank swings and punches a player
 * @remarks This forward will ONLY trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param tank			tank client index
 * @param rock			the claw entity index
 * @param player		the player being hit
 *
 * @noreturn
 */
forward void TankClaw_OnPlayerHit_PostHandled(int tank, int claw, int player);

/**
 * @brief Called whenever CTankRock::Detonate() is invoked
 * @remarks When a tank rock hits something and explodes
 *
 * @param tank			tank client index
 * @param rock			the rock entity index
 *
 * @noreturn
 */
forward void TankRock_OnDetonate(int tank, int rock);

/**
 * @brief Called whenever CTankRock::OnRelease(Vector const&, QAngle const&, Vector const&, Vector const&) is invoked
 * @remarks When a tank rock is thrown
 *
 * @param tank			tank client index (can be -1 if the rock was created by the native "TankRockPrj" or the "env_rock_launcher" entity)
 * @param rock			the rock entity index
 * @param vecPos		the position vector of the rock
 * @param vecAng		the angle vector of the rock
 * @param vecVel		the velocity vector of the rock
 * @param vecRot		the rotation vector of the rock
 *
 * @return				Plugin_Changed to modify the vector values, Plugin_Continue otherwise
 */
forward Action TankRock_OnRelease(int tank, int rock, float vecPos[3], float vecAng[3], float vecVel[3], float vecRot[3]);

/**
 * @brief Called whenever CTankRock::OnRelease(Vector const&, QAngle const&, Vector const&, Vector const&) is invoked
 * @remarks When a tank rock is thrown
 * @remarks Forward shows the final values that may have been changed from the relative pre-hook
 *
 * @param tank			tank client index (can be -1 if the rock was created by the native "TankRockPrj" or the "env_rock_launcher" entity)
 * @param rock			the rock entity index
 * @param vecPos		the position vector of the rock
 * @param vecAng		the angle vector of the rock
 * @param vecVel		the velocity vector of the rock
 * @param vecRot		the rotation vector of the rock
 *
 * @noreturn
 */
forward void TankRock_OnRelease_Post(int tank, int rock, const float vecPos[3], const float vecAng[3], const float vecVel[3], const float vecRot[3]);

/**
 * @brief Called whenever CTankRock::BounceTouch is invoked
 * @remarks When a tank rock touches an entity to bounce
 *
 * @param tank			tank client index (can be -1 if the rock was created by the native "TankRockPrj" or the "env_rock_launcher" entity)
 * @param rock			the rock entity index
 * @param entity		the entity index it touched (can be 0 for world)
 *
 * @return				Plugin_Handled to prevent exploding/hitting(?) - this will cause the rock to float in position and call TankRock_BounceTouch over and over, manually teleport to bounce off an object, Plugin_Continue otherwise
 */
forward Action TankRock_BounceTouch(int tank, int rock, int entity);

/**
 * @brief Called whenever CTankRock::BounceTouch is invoked
 * @remarks When a tank rock touches an entity to bounce
 * @remarks This forward will not trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param tank			tank client index (can be -1 if the rock was created by the native "TankRockPrj" or the "env_rock_launcher" entity)
 * @param rock			the rock entity index
 * @param entity		the entity index it touched (can be 0 for world)
 *
 * @noreturn
 */
forward void TankRock_BounceTouch_Post(int tank, int rock, int entity);

/**
 * @brief Called whenever CTankRock::BounceTouch is invoked
 * @remarks When a tank rock touches an entity to bounce
 * @remarks This forward will ONLY trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param tank			tank client index (can be -1 if the rock was created by the native "TankRockPrj" or the "env_rock_launcher" entity)
 * @param rock			the rock entity index
 * @param entity		the entity index it touched (can be 0 for world)
 *
 * @noreturn
 */
forward void TankRock_BounceTouch_PostHandled(int tank, int rock, int entity);

/**
 * @brief Called whenever CDirector::TryOfferingTankBot is invoked
 * @remarks Is used for displaying the "X gets Tank" window and transferring Tank control
 *
 * @param tank_index		Client index of the tank
 * @param enterStasis		Is the tank in stasis
 *
 * @return					Plugin_Handled to block window from showing and to keep Tank Bot, Plugin_Changed to use overwritten values from plugin, Plugin_Continue otherwise
 */
forward Action OnTryOfferingTankBot(int tank_index, bool &enterStasis);

/**
 * @brief Called whenever CDirector::TryOfferingTankBot is invoked
 * @remarks Is used for displaying the "X gets Tank" window and transferring Tank control
 * @remarks This forward will not trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param tank_index		Client index of the tank
 * @param enterStasis		Is the tank in stasis
 *
 * @noreturn
 */
forward void OnTryOfferingTankBot_Post(int tank_index, bool enterStasis);

/**
 * @brief Called whenever CDirector::TryOfferingTankBot is invoked
 * @remarks Is used for displaying the "X gets Tank" window and transferring Tank control
 * @remarks This forward will ONLY trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param tank_index		Client index of the tank (can be -1 when blocked)
 * @param enterStasis		Is the tank in stasis
 *
 * @noreturn
 */
forward void OnTryOfferingTankBot_PostHandled(int tank_index, bool enterStasis);

/**
 * @brief Called whenever CThrow::ActivateAbility(void) is invoked
 * @remarks Called when a tank throws a rock. Blocking this call will keep the tank from throwing a rock
 *
 * @param ability	ability_throw entity index
 *
 * @return			Plugin_Handled to block, Plugin_Continue otherwise
 */
forward Action OnCThrowActivate(int ability);

/**
 * @brief Called whenever CThrow::ActivateAbility(void) is invoked
 * @remarks Called when a tank throws a rock. Blocking this call will keep the tank from throwing a rock
 * @remarks This forward will not trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param ability	ability_throw entity index
 *
 * @noreturn
 */
forward void OnCThrowActivate_Post(int ability);

/**
 * @brief Called whenever CThrow::ActivateAbility(void) is invoked
 * @remarks Called when a tank throws a rock. Blocking this call will keep the tank from throwing a rock
 * @remarks This forward will ONLY trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param ability	ability_throw entity index
 *
 * @noreturn
 */
forward void OnCThrowActivate_PostHandled(int ability);

/**
 * @brief Called when CBaseAnimating::SelectWeightedSequence(int Activity) is invoked with tank attack activity
 * @remarks Called whenever a tank uses their primary (punch) or secondary (throw) attack (uses ACT_* activity numbers)
 *
 * This detour uses activity sequence numbers
 *
 * @param client	the client that is playing as tank
 * @param sequence	current selected activity for attack, option to override the return value with it
 *
 * L4D2:
 * ACT_HULK_THROW				761
 * ACT_TANK_OVERHEAD_THROW		762
 * ACT_HULK_ATTACK_LOW			763
 * ACT_TERROR_ATTACK_MOVING		790
 *
 * L4D1:
 * ACT_HULK_THROW				1254
 * ACT_TANK_OVERHEAD_THROW		1255
 * ACT_HULK_ATTACK_LOW			1256
 * ACT_TERROR_ATTACK_MOVING		1282
 *
 * @return			Plugin_Handled to override return value, Plugin_Continue otherwise
 */
forward Action OnSelectTankAttackPre(int client, int &sequence);

/**
 * @brief Called when CBaseAnimating::SelectWeightedSequence(int Activity) is invoked with tank attack activity
 * @remarks Called whenever a tank uses their primary (punch) or secondary (throw) attack (uses m_nSequence animation numbers)
 *
 * This detour uses models m_nSequence numbers
 *
 * @param client	the client that is playing as tank
 * @param sequence	current selected activity for attack, option to override the return value with it
 *
 * @remarks	sequences, for L4D1:
 * @remarks	sequences(punches)	38 (uppercut), 41 (right hook), 43 (left hook), 44 and 45 (pounding the ground)
 * @remarks	sequences(throws)	46 (undercut), 47 (1handed overhand), 48 (throw from the hip), 49 (2handed overhand)
 *
 * @remarks	sequences, for L4D2:
 * @remarks	sequences(punches)	40 uppercut), 43 (right hook), 45 (left hook), 46 and 47 (pounding the ground)
 * @remarks	sequences(throws)	48 undercut), 49 (1handed overhand), 50 (throw from the hip), 51 (2handed overhand)
 *
 * @return			Plugin_Handled to override return value, Plugin_Continue otherwise
 */
forward Action OnSelectTankAttack(int client, int &sequence);

/**
 * @brief Called whenever CTerrorMeleeWeapon::StartMeleeSwing(CTerrorPlayer *, bool) is invoked
 * @remarks Called when a player uses their melee weapons primary attack. This is before the game
 *			reads the melee weapon data (model etc) and decides if he CAN attack at all
 *
 * @return			Plugin_Handled to block, Plugin_Continue otherwise
 */
forward Action OnStartMeleeSwing(int client, bool primaryAttack);

/**
 * @brief Called whenever CTerrorMeleeWeapon::StartMeleeSwing(CTerrorPlayer *, bool) is invoked
 * @remarks Called when a player uses their melee weapons primary attack. This is before the game
 *			reads the melee weapon data (model etc) and decides if he CAN attack at all
 * @remarks This forward will not trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @noreturn
 */
forward void OnStartMeleeSwing_Post(int client, bool primaryAttack);

/**
 * @brief Called whenever CTerrorMeleeWeapon::StartMeleeSwing(CTerrorPlayer *, bool) is invoked
 * @remarks Called when a player uses their melee weapons primary attack. This is before the game
 *			reads the melee weapon data (model etc) and decides if he CAN attack at all
 * @remarks This forward will ONLY trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @noreturn
 */
forward void OnStartMeleeSwing_PostHandled(int client, bool primaryAttack);

/**
 * @brief Called whenever CTerrorMeleeWeapon::GetDamageForVictim() is invoked
 * @remarks Called to calculate the damage when a melee weapon hits something
 * @remarks A headshot on Common Infected will still kill them
 * @remarks Could maybe set the weapon attribute "L4D2BoolMeleeWeapon_Decapitates" to avoid killing on headshot. Please report success if you try
 *
 * @param client	the client swinging the melee weapon
 * @param weapon	the weapon entity index
 * @param victim	the victim being hit by the melee weapon
 * @param damage	the amount of damage to inflict on the victim
 *
 * @return			Plugin_Handled to block, Plugin_Changed to change damage, Plugin_Continue otherwise
 */
forward Action MeleeGetDamageForVictim(int client, int weapon, int victim, float &damage);

/**
 * @brief Called whenever CTerrorPlayer::DoAnimationEvent is invoked
 * @note The event argument is NOT the same as the sequence numbers found in the model viewer
 * @note You can get the number for your animation by looking at the disasm for virtual calls to DoAnimationEvent
 *
 * @return			Plugin_Handled to block, Plugin_Changed to modify value, Plugin_Continue otherwise
 */
forward Action OnDoAnimationEvent(int client, int &event, int &variant_param);

/**
 * @brief Called whenever CTerrorPlayer::DoAnimationEvent is invoked
 * @note The event argument is NOT the same as the sequence numbers found in the model viewer
 * @note You can get the number for your animation by looking at the disasm for virtual calls to DoAnimationEvent
 * @remarks This forward will not trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @noreturn
 */
forward void OnDoAnimationEvent_Post(int client, int event, int variant_param);

/**
 * @brief Called whenever CTerrorPlayer::DoAnimationEvent is invoked
 * @note The event argument is NOT the same as the sequence numbers found in the model viewer
 * @note You can get the number for your animation by looking at the disasm for virtual calls to DoAnimationEvent
 * @remarks This forward will ONLY trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @noreturn
 */
forward void OnDoAnimationEvent_PostHandled(int client, int event, int variant_param);

/**
 * @brief Called whenever CDirectorScriptedEventManager::SendInRescueVehicle(void) is invoked
 * @remarks Called when the last Finale stage is reached and the Rescue means becomes 'available'
 *			Take note this forward WILL fire upon using the native of the same function
 *
 * @return			Plugin_Handled to block, Plugin_Continue otherwise
 */
// 2020 Left4DHooks update: Blocked on L4D1/L4D2 Linux to prevent crashes. Waiting for DHooks update to support object returns
forward Action OnSendInRescueVehicle();

/**
 * @brief Called whenever CDirectorScriptedEventManager::ChangeFinaleStage is invoked
 * @remarks Called when the director stage changes
 * @remarks some values for FinaleStageType: 1 - Finale Started; 6 - Rescue Vehicle Ready; 7 - Zombie Hordes; 8 - Tank; 10 - Combat Respite (nothing spawns)
 * @remarks SendInRescueVehicle does not depend on Finale Stage being 6, that only signals endless Hordes/Tanks
 * @remarks Can use the "FINALE_*" enums (search for them above) for the finaleType value
 *
 * @param FinaleStageType	integer value
 *
 * @return			Plugin_Handled to block, Plugin_Changed to change finaleType, Plugin_Continue otherwise
 */
forward Action OnChangeFinaleStage(int &finaleType, const char[] arg);

/**
 * @brief Called whenever CDirectorScriptedEventManager::ChangeFinaleStage is invoked
 * @remarks Called when the director stage changes
 * @remarks some values for FinaleStageType: 1 - Finale Started; 6 - Rescue Vehicle Ready; 7 - Zombie Hordes; 8 - Tank; 10 - Combat Respite (nothing spawns)
 * @remarks SendInRescueVehicle does not depend on Finale Stage being 6, that only signals endless Hordes/Tanks
 * @remarks Can use the "FINALE_*" enums (search for them above) for the finaleType value
 * @remarks This forward will not trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param FinaleStageType	integer value
 *
 * @noreturn
 */
forward void OnChangeFinaleStage_Post(int finaleType, const char[] arg);

/**
 * @brief Called whenever CDirectorScriptedEventManager::ChangeFinaleStage is invoked
 * @remarks Called when the director stage changes
 * @remarks some values for FinaleStageType: 1 - Finale Started; 6 - Rescue Vehicle Ready; 7 - Zombie Hordes; 8 - Tank; 10 - Combat Respite (nothing spawns)
 * @remarks SendInRescueVehicle does not depend on Finale Stage being 6, that only signals endless Hordes/Tanks
 * @remarks Can use the "FINALE_*" enums (search for them above) for the finaleType value
 * @remarks This forward will ONLY trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param FinaleStageType	integer value
 *
 * @noreturn
 */
forward void OnChangeFinaleStage_PostHandled(int finaleType, const char[] arg);

/**
 * @brief Called whenever CDirectorVersusMode::EndVersusModeRound(bool) is invoked
 * @remarks Called before score calculations and the scoreboard display
 *
 * @param countSurvivors	True if the survival multiplier count needs to be nonzero. I guess
 * @remarks Not sure what bool does exactly yet. Just monitor it. If true, survivors will be counted for multiplier. If false, survival multiplier will be set to 0
 * @remarks A lot of Score calculations happen on this function, and the round-end scoreboard comes up doing this. Don't block unless you're sure you can reproduce this logic
 *
 * @param countSurvivors		False = Survivors didn't make it to saferoom. True = Survivors made to the saferoom
 *
 * @return			Plugin_Handled to block, Plugin_Continue otherwise
 */
forward Action OnEndVersusModeRound(bool countSurvivors);

/**
 * @brief Called after CDirectorVersusMode::EndVersusModeRound(bool)
 * @remarks Called after all score calculations are complete and the scoreboard shows
 * @remarks Called after all score calculations inside CDirectorVersusMode::EndVersusModeRound(bool). This good forward to replace standard "round_end" hook
 * @remarks This forward will not trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @noreturn
 */
forward void OnEndVersusModeRound_Post();

/**
 * @brief Called after CDirectorVersusMode::EndVersusModeRound(bool)
 * @remarks Called after all score calculations are complete and the scoreboard shows
 * @remarks Called after all score calculations inside CDirectorVersusMode::EndVersusModeRound(bool). This good forward to replace standard "round_end" hook
 * @remarks This forward will ONLY trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @noreturn
 */
forward void OnEndVersusModeRound_PostHandled();


/**
 * @brief Called whenever CTerrorPlayer::OnLedgeGrabbed(CTerrorPlayer *this, const Vector *) is invoked
 * @remarks Called when a player is about to grab a ledge
 *
 * @param client	client grabbing the ledge
 *
 * @return			Plugin_Handled to prevent grabbing, Plugin_Continue otherwise
 */
forward Action OnLedgeGrabbed(int client);

/**
 * @brief Called whenever CTerrorPlayer::OnLedgeGrabbed(CTerrorPlayer *this, const Vector *) is invoked
 * @remarks Called when a player is about to grab a ledge
 * @remarks This forward will not trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param client	client grabbing the ledge
 *
 * @noreturn
 */
forward void OnLedgeGrabbed_Post(int client);

/**
 * @brief Called whenever CTerrorPlayer::OnLedgeGrabbed(CTerrorPlayer *this, const Vector *) is invoked
 * @remarks Called when a player is about to grab a ledge
 * @remarks This forward will ONLY trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param client	client grabbing the ledge
 *
 * @noreturn
 */
forward void OnLedgeGrabbed_PostHandled(int client);

/**
 * @brief Called when CTerrorPlayer::OnRevived(void) is invoked
 * @remarks Called post-revive so all data values are post-revive status
 *
 * @param client	the client that has been revived
 *
 * @noreturn
 */
forward void OnRevived(int client);

/**
 * @brief Called whenever CTerrorWeapon::OnSwingStart(CTerrorWeapon *this) is invoked
 * @remarks Called when a Survivor shoves
 * @remarks Blocking has no effect so this function is void only
 *
 * @param client	the client that did the shoving
 * @param weapon	the weapon being held when shoving
 *
 * @noreturn
 */
forward void OnSwingStart(int client, int weapon);

/**
 * @brief Called whenever CTerrorPlayer::OnShovedBySurvivor(CTerrorPlayer, Vector&) is invoked
 * @remarks L4D2 only uses this on Special Infected
 * @remarks Blocks hunter dead stop
 *
 * @param client	the client that did the shoving
 * @param victim	the client that was shoved (CAUTION retrieved from function pointer, don't meddle with it)
 * @param vecDir	Vector Angle of Shoveforce
 *
 * @return			Plugin_Handled to block melee effect (staggering), Plugin_Continue otherwise
 */
forward Action OnShovedBySurvivor(int client, int victim, const float vecDir[3]);

/**
 * @brief Called whenever CTerrorPlayer::OnShovedBySurvivor(CTerrorPlayer, Vector&) is invoked
 * @remarks L4D2 only uses this on Special Infected
 * @remarks Blocks hunter dead stop
 * @remarks This forward will not trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param client	the client that did the shoving
 * @param victim	the client that was shoved (CAUTION retrieved from function pointer, don't meddle with it)
 * @param vecDir	Vector Angle of Shoveforce
 *
 * @noreturn
 */
forward void OnShovedBySurvivor_Post(int client, int victim, const float vecDir[3]);

/**
 * @brief Called whenever CTerrorPlayer::OnShovedBySurvivor(CTerrorPlayer, Vector&) is invoked
 * @remarks L4D2 only uses this on Special Infected
 * @remarks Blocks hunter dead stop
 * @remarks This forward will ONLY trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param client	the client that did the shoving
 * @param victim	the client that was shoved (CAUTION retrieved from function pointer, don't meddle with it)
 * @param vecDir	Vector Angle of Shoveforce
 *
 * @noreturn
 */
forward void OnShovedBySurvivor_PostHandled(int client, int victim, const float vecDir[3]);

/**
 * @brief Called whenever CTerrorWeapon::OnHit(CGameTrace &, Vector const&, bool) is invoked
 * @remarks Called for every single shovable and even some of the unshovable entities in the game
 *
 * @param client	survivor who did the shoving
 * @param entity	entity that is about to get shoved
 * @param weapon	weapon that has been held while shoving
 * @param vecDir	stagger direction
 * @param bIsHighPounce		a boolean to determine if it was a pounce from a height or not; reliable to a certain degree and should only be considered for hunters
 * @param bIsHighPounce		sometimes reset to 0 when punched before the detour retrieves the information
 *
 * @return			Plugin_Handled to block, Plugin_Continue otherwise
 */
forward Action OnEntityShoved(int client, int entity, int weapon, float vecDir[3], bool bIsHighPounce);

/**
 * @brief Called whenever CTerrorWeapon::OnHit(CGameTrace &, Vector const&, bool) is invoked
 * @remarks Called for every single shovable and even some of the unshovable entities in the game
 * @remarks This forward will not trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param client	survivor who did the shoving
 * @param entity	entity that is about to get shoved
 * @param weapon	weapon that has been held while shoving
 * @param vecDir	stagger direction
 * @param bIsHighPounce		a boolean to determine if it was a pounce from a height or not; reliable to a certain degree and should only be considered for hunters
 * @param bIsHighPounce		sometimes reset to 0 when punched before the detour retrieves the information
 *
 * @noreturn
 */
forward void OnEntityShoved_Post(int client, int entity, int weapon, const float vecDir[3], bool bIsHighPounce);

/**
 * @brief Called whenever CTerrorWeapon::OnHit(CGameTrace &, Vector const&, bool) is invoked
 * @remarks Called for every single shovable and even some of the unshovable entities in the game
 * @remarks This forward will ONLY trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param client	survivor who did the shoving
 * @param entity	entity that is about to get shoved
 * @param weapon	weapon that has been held while shoving
 * @param vecDir	stagger direction
 * @param bIsHighPounce		a boolean to determine if it was a pounce from a height or not; reliable to a certain degree and should only be considered for hunters
 * @param bIsHighPounce		sometimes reset to 0 when punched before the detour retrieves the information
 *
 * @noreturn
 */
forward void OnEntityShoved_PostHandled(int client, int entity, int weapon, const float vecDir[3], bool bIsHighPounce);

/**
 * @brief Called whenever CTerrorPlayer::OnStaggered(CBaseEntity *, Vector const *) is invoked
 * @remarks Source is always null for Charger impacts (Valve)
 *
 * @param client	the client that is about to get staggered
 * @param source	the client that is about to stagger the client
 *
 * @return			Plugin_Handled to block, Plugin_Continue otherwise
 */
forward Action OnStagger(int client, int source);

/**
 * @brief Called whenever CTerrorPlayer::OnStaggered(CBaseEntity *, Vector const *) is invoked
 * @remarks Source is always null for Charger impacts (Valve)
 * @remarks This forward will not trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param client	the client that is about to get staggered
 * @param source	the client that is about to stagger the client
 *
 * @noreturn
 */
forward void OnStagger_Post(int client, int source);

/**
 * @brief Called whenever CTerrorPlayer::OnStaggered(CBaseEntity *, Vector const *) is invoked
 * @remarks Source is always null for Charger impacts (Valve)
 * @remarks This forward will ONLY trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param client	the client that is about to get staggered
 * @param source	the client that is about to stagger the client
 *
 * @noreturn
 */
forward void OnStagger_PostHandled(int client, int source);

/**
 * @brief Called when CTerrorPlayer::CancelStagger() is invoked
 * @remarks Called when a players staggering is about to be cancelled
 *
 * @param client		Client index of the player
 *
 * @return				Plugin_Handled to allow staggering to continue, Plugin_Continue to allow
 **/
forward Action OnCancelStagger(int client);

/**
 * @brief Called when CTerrorPlayer::CancelStagger() is invoked
 * @remarks Called when a players staggering is being cancelled
 * @remarks This will not trigger if the cancel is being blocked by other plugins
 * @remarks This forward will not trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param client		Client index of the player
 *
 * @return				Plugin_Handled to allow staggering to continue, Plugin_Continue to allow
 **/
forward void OnCancelStagger_Post(int client);

/**
 * @brief Called when CTerrorPlayer::CancelStagger() is invoked
 * @remarks Called when a players staggering has not been cancelled
 * @remarks This will trigger if the cancel is being blocked by other plugins
 * @remarks This forward will ONLY trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param client		Client index of the player
 *
 * @return				Plugin_Handled to allow staggering to continue, Plugin_Continue to allow
 **/
forward void OnCancelStagger_PostHandled(int client);

/**
 * @brief Called when CTerrorPlayer::Fling(Vector const&, PlayerAnimEvent_t, CBaseCombatCharacter*, float) is invoked
 * @remarks Called when a player is flung to the ground
 *
 * @param client		Client index of the player
 * @param attacker		Client index of the attacker
 * @param vecDir		Vector direction of the fling
 *
 * @return				Plugin_Handled to block fling, Plugin_Continue to allow
 **/
forward Action OnPlayerFling(int client, int attacker, float vecDir[3]);

/**
 * @brief Called when CTerrorPlayer::Fling(Vector const&, PlayerAnimEvent_t, CBaseCombatCharacter*, float) is invoked
 * @remarks Called when a player is flung to the ground
 * @remarks This will not trigger if the fling is being blocked by other plugins
 * @remarks This forward will not trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param client		Client index of the player
 * @param attacker		Client index of the attacker
 * @param vecDir		Vector direction of the fling
 *
 * @noreturn
 **/
forward void OnPlayerFling_Post(int client, int attacker, const float vecDir[3]);

/**
 * @brief Called when CTerrorPlayer::Fling(Vector const&, PlayerAnimEvent_t, CBaseCombatCharacter*, float) is invoked
 * @remarks Called when a player is flung to the ground
 * @remarks This will trigger if the fling is being blocked by other plugins
 * @remarks This forward will ONLY trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param client		Client index of the player
 * @param attacker		Client index of the attacker
 * @param vecDir		Vector direction of the fling
 *
 * @noreturn
 **/
forward void OnPlayerFling_PostHandled(int client, int attacker, const float vecDir[3]);

/**
 * @brief Called when CTerrorPlayer::IsMotionControlledXY is invoked
 * @remarks Called when a player is staggering or a Hunter has been knocked off someone
 * @remarks Blocking this will allow the player to fall with gravity instead of floating in the air
 *
 * @param client		Client index of the player
 * @param activity		The activity sequence playing that has a fixed set of motions
 *
 * @return				Plugin_Handled to block, Plugin_Continue otherwise
 **/
forward Action OnMotionControlledXY(int client, int activity);

/**
 * @brief Called whenever CTerrorPlayer::OnShovedByPounceLanding(CTerrorPlayer*) is invoked
 *
 * @param victim	the survivor that is about to get stumbled as a result of "attacker" capping someone in close proximity
 * @param attacker	the SI that is about to cause a stumble as a result of capping someone in close proximity to a survivor
 *
 * @return			Plugin_Handled to block, Plugin_Continue otherwise
 */
forward Action OnPounceOrLeapStumble(int victim, int attacker);

/**
 * @brief Called whenever CTerrorPlayer::OnShovedByPounceLanding(CTerrorPlayer*) is invoked
 * @remarks This forward will not trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param victim	the survivor that is about to get stumbled as a result of "attacker" capping someone in close proximity
 * @param attacker	the SI that is about to cause a stumble as a result of capping someone in close proximity to a survivor
 *
 * @noreturn
 */
forward void OnPounceOrLeapStumble_Post(int victim, int attacker);

/**
 * @brief Called whenever CTerrorPlayer::OnShovedByPounceLanding(CTerrorPlayer*) is invoked
 * @remarks This forward will ONLY trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param victim	the survivor that is about to get stumbled as a result of "attacker" capping someone in close proximity
 * @param attacker	the SI that is about to cause a stumble as a result of capping someone in close proximity to a survivor
 *
 * @noreturn
 */
forward void OnPounceOrLeapStumble_PostHandled(int victim, int attacker);

/**
 * @brief Called when CTerrorPlayer::OnKnockedDown(CTerrorPlayer*) is invoked
 * @remarks Called when someone is about to be hit by a Tank rock or lunged by a Hunter
 * @remarks You can use the "KNOCKDOWN_*" enum values for the reason
 * @remarks Called multiple times when someone is about to be pounced by a Hunter
 *
 * @param victim		Client index of the victim
 * @param reason		The Knockdown reason type. 1=Hunter lunge, 2=Tank rock, 3=Charger impact
 *
 * @return				Plugin_Handled to block fling, Plugin_Continue to allow
 **/
forward Action OnKnockedDown(int client, int reason);

/**
 * @brief Called when CTerrorPlayer::OnKnockedDown(CTerrorPlayer*) is invoked
 * @remarks Called when someone is about to be hit by a Tank rock or lunged by a Hunter
 * @remarks Called multiple times when someone is about to be pounced by a Hunter
 * @remarks You can use the "KNOCKDOWN_*" enum values for the reason
 * @remarks This forward will not trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param victim		Client index of the victim
 * @param reason		The Knockdown reason type. 1=Hunter lunge, 2=Tank rock, 3=Charger impact
 *
 * @noreturn
 **/
forward void OnKnockedDown_Post(int client, int reason);

/**
 * @brief Called when CTerrorPlayer::OnKnockedDown(CTerrorPlayer*) is invoked
 * @remarks Called when someone is about to be hit by a Tank rock or lunged by a Hunter
 * @remarks Called multiple times when someone is about to be pounced by a Hunter
 * @remarks You can use the "KNOCKDOWN_*" enum values for the reason
 * @remarks This forward will ONLY trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param victim		Client index of the victim
 * @param reason		The Knockdown reason type. 1=Hunter lunge, 2=Tank rock, 3=Charger impact
 *
 * @noreturn
 **/
forward void OnKnockedDown_PostHandled(int client, int reason);

/**
 * @brief Called when ThrowImpactedSurvivor(CTerrorPlayer *, CTerrorPlayer *, float, bool) is invoked
 * @remarks Called when a player is about to be flung by a Charger impact
 *
 * @param attacker		Client index of the attacker
 * @param victim		Client index of the victim
 *
 * @return				Plugin_Handled to block fling, Plugin_Continue to allow
 **/
forward Action OnThrowImpactedSurvivor(int attacker, int victim);

/**
 * @brief Called when ThrowImpactedSurvivor(CTerrorPlayer *, CTerrorPlayer *, float, bool) is invoked
 * @remarks Called when a player is flung by a Charger impact
 * @remarks This forward will not trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param attacker		Client index of the attacker
 * @param victim		Client index of the victim
 *
 * @noreturn
 **/
forward void OnThrowImpactedSurvivor_Post(int attacker, int victim);

/**
 * @brief Called when ThrowImpactedSurvivor(CTerrorPlayer *, CTerrorPlayer *, float, bool) is invoked
 * @remarks Called when a player is flung by a Charger impact
 * @remarks This forward will ONLY trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param attacker		Client index of the attacker
 * @param victim		Client index of the victim
 *
 * @noreturn
 **/
forward void OnThrowImpactedSurvivor_PostHandled(int attacker, int victim);

/**
 * @brief Called when CDeathFallCamera::Enable(CBasePlayer*) is invoked
 * @remarks Called when a player is falling in a fatal zone
 * @remarks Does not trigger for all cases when someone is fatally falling
 * @remarks Use this forward to check if the current map has death fall cameras (fatal falls)
 *
 * @param client		Client index of the player. Can be 0
 * @param camera		Death fall camera index
 *
 * @return				Plugin_Handled to block the death fall camera, Plugin_Continue to allow
 **/
forward Action OnFatalFalling(int client, int camera);

/**
 * @brief Called when CTerrorPlayer::OnFalling() is invoked
 * @remarks Called when a player is falling
 *
 * @param client		Client index of the player
 **/
forward void OnFalling(int client);

/**
 * @brief Called when CTerrorPlayer::Cough() is invoked
 * @remarks Called when a player is coughing, most likely from Smoker Cloud, but possibly called by other plugins
 *
 * @param client		Client index of the player affected
 * @param attacker		Client index who caused the cough, can be 0 after a while when the AI special infected is kicked
 *
 * @return				return Plugin_Handled to block, Plugin_Continue otherwise
 **/
forward Action OnPlayerCough(int client, int attacker);

/**
 * @brief Called when CTerrorPlayer::Cough() is invoked
 * @remarks Called when a player is coughing, most likely from Smoker Cloud, but possibly called by other plugins
 * @remarks This forward will not trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param client		Client index of the player affected
 * @param attacker		Client index who caused the cough, can be 0 after a while when the AI special infected is kicked
 *
 * @noreturn
 **/
forward void OnPlayerCough_Post(int client, int attacker);

/**
 * @brief Called when CTerrorPlayer::Cough() is invoked
 * @remarks Called when a player is coughing, most likely from Smoker Cloud, but possibly called by other plugins
 * @remarks This forward will ONLY trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param client		Client index of the player affected
 * @param attacker		Client index who caused the cough, can be 0 after a while when the AI special infected is kicked
 *
 * @noreturn
 **/
forward void OnPlayerCough_PostHandled(int client, int attacker);

/**
 * @brief Called when CTerrorPlayer::OnIncapacitatedAsSurvivor() is invoked
 * @remarks Called when a player is about to be incapacitated
 *
 * @param client		Client index of the player affected
 * @param inflictor		The inflictor entity index
 * @param attacker		The attacker entity index
 * @param damage		Amount of damage being caused
 * @param damagetype	Type of damage being caused
 *
 * @return				return Plugin_Handled to block, Plugin_Changed to modify values, Plugin_Continue otherwise
 **/
forward Action OnIncapacitated(int client, int &inflictor, int &attacker, float &damage, int &damagetype, int &weapon);

/**
 * @brief Called when CTerrorPlayer::OnIncapacitatedAsSurvivor() is invoked
 * @remarks Called when a player is about to be incapacitated
 * @remarks This forward will not trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param client		Client index of the player affected
 * @param inflictor		The inflictor entity index
 * @param attacker		The attacker entity index
 * @param damage		Amount of damage being caused
 * @param damagetype	Type of damage being caused
 *
 * @noreturn
 **/
forward void OnIncapacitated_Post(int client, int inflictor, int attacker, float damage, int damagetype, int weapon);

/**
 * @brief Called when CTerrorPlayer::OnIncapacitatedAsSurvivor() is invoked
 * @remarks Called when a player is about to be incapacitated
 * @remarks This forward will ONLY trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param client		Client index of the player affected
 * @param inflictor		The inflictor entity index
 * @param attacker		The attacker entity index
 * @param damage		Amount of damage being caused
 * @param damagetype	Type of damage being caused
 *
 * @noreturn
 **/
forward void OnIncapacitated_PostHandled(int client, int inflictor, int attacker, float damage, int damagetype, int weapon);

/**
 * @brief Called when CTerrorPlayer::DropWeapons() is invoked
 * @remarks Called when a player dies, listing their currently held weapons and objects that are being dropped
 * @remarks Array index is as follows:
 * @remarks [0] = L4DWeaponSlot_Primary
 * @remarks [1] = L4DWeaponSlot_Secondary
 * @remarks [2] = L4DWeaponSlot_Grenade
 * @remarks [3] = L4DWeaponSlot_FirstAid
 * @remarks [4] = L4DWeaponSlot_Pills
 * @remarks [5] = Held item (e.g. weapon_gascan, weapon_gnome etc)
 *
 * @param client		Client index of the player who died
 * @param weapons		Array of weapons dropped, valid entity index or -1 if empty
 *
 * @noreturn
 **/
forward void OnDeathDroppedWeapons(int client, int weapons[6]);

/**
 * @brief Called whenever CInferno::Spread(Vector const&) is invoked (only for spitters -- ignores fire)
 *
 * @param spitter	 	spitter that spat (:D)
 * @param projectile	spitter's projectile entity
 * @param x				x coordinate of the new acid puddle (can be overridden)
 * @param y				y coordinate of the new acid puddle (can be overridden)
 * @param z				z coordinate of the new acid puddle (can be overridden)
 *
 * @return			Plugin_Handled to block, Plugin_Continue otherwise
 */
forward Action OnSpitSpread(int spitter, int projectile, float &x, float &y, float &z);

/**
 * @brief Called whenever CTerrorPlayer::Extinguish() is invoked
 * @remarks Called when a player (Survivor or Special Infected) is about to be extinguished
 *
 * @param client			the client who is about to be extinguished
 *
 * @return					Plugin_Handled to block extinguishing, Plugin_Continue otherwise
 */
forward Action PlayerExtinguish(int client);

/**
 * @brief Called whenever BossZombiePlayer(CTerrorPlayer *, int, CBaseEntity *) is invoked
 * @remarks Called when Special Infected are targeting a victim
 *
 * @param specialInfected	the SI entity index
 * @param lastTarget		the last targeted chosen victim
 *
 * @return					Plugin_Handled to block, Plugin_Changed to use overwritten values from plugin, Plugin_Continue otherwise
 */
forward Action OnChooseVictim_Pre(int specialInfected, int &lastTarget);

/**
 * @brief Called whenever BossZombiePlayer(CTerrorPlayer *, int, CBaseEntity *) is invoked
 * @remarks Called when Special Infected are targeting a victim
 *
 * @param specialInfected	the SI entity index
 * @param curTarget			the survivor player index who is chosen victim
 *
 * @return					Plugin_Handled to block, Plugin_Changed to use overwritten values from plugin, Plugin_Continue otherwise
 */
forward Action OnChooseVictim(int specialInfected, int &curTarget);

/**
 * @brief Called whenever CTerrorPlayer::OnPouncedOnSurvivor() is invoked
 * @remarks Called when a Survivor player is about to be pounced on by a Hunter
 *
 * @param victim			the client who's being pounced
 * @param attacker			the Hunter pouncing on someone
 *
 * @return					Plugin_Handled to block, Plugin_Continue otherwise
 */
forward Action OnPouncedOnSurvivor(int victim, int attacker);

/**
 * @brief Called whenever CTerrorPlayer::OnPouncedOnSurvivor() is invoked
 * @remarks Called when a Survivor player is about to be pounced on by a Hunter
 * @remarks This forward will not trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param victim			the client who's being pounced
 * @param attacker			the Hunter pouncing on someone
 *
 * @noreturn
 */
forward void OnPouncedOnSurvivor_Post(int victim, int attacker);

/**
 * @brief Called whenever CTerrorPlayer::OnPouncedOnSurvivor() is invoked
 * @remarks Called when a Survivor player is about to be pounced on by a Hunter
 * @remarks This forward will ONLY trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param victim			the client who's being pounced
 * @param attacker			the Hunter pouncing on someone
 *
 * @noreturn
 */
forward void OnPouncedOnSurvivor_PostHandled(int victim, int attacker);

/**
 * @brief Called whenever CTerrorPlayer::GrabVictimWithTongue() is invoked
 * @remarks Called when a Survivor player is about to be grabbed by a Smoker
 *
 * @param victim			the client who's being grabbed
 * @param attacker			the Smoker grabbing someone
 *
 * @return					Plugin_Handled to block, Plugin_Continue otherwise
 */
forward Action OnGrabWithTongue(int victim, int attacker);

/**
 * @brief Called whenever CTerrorPlayer::GrabVictimWithTongue() is invoked
 * @remarks Called when a Survivor player is grabbed by a Smoker
 * @remarks This forward will not trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param victim			the client who's being grabbed
 * @param attacker			the Smoker grabbing someone
 *
 * @noreturn
 */
forward void OnGrabWithTongue_Post(int victim, int attacker);

/**
 * @brief Called whenever CTerrorPlayer::GrabVictimWithTongue() is invoked
 * @remarks Called when a Survivor player is grabbed by a Smoker
 * @remarks This forward will ONLY trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param victim			the client who's being grabbed
 * @param attacker			the Smoker grabbing someone
 *
 * @noreturn
 */
forward void OnGrabWithTongue_PostHandled(int victim, int attacker);

/**
 * @brief Called whenever CTerrorPlayer::OnLeptOnSurvivor() is invoked
 * @remarks Called when a Survivor player is about to be ridden by a Jockey
 *
 * @param victim			the client who's being grabbed
 * @param attacker			the Jockey grabbing someone
 *
 * @return					Plugin_Handled to block, Plugin_Continue otherwise
 */
forward Action OnJockeyRide(int victim, int attacker);

/**
 * @brief Called whenever CTerrorPlayer::OnLeptOnSurvivor() is invoked
 * @remarks Called when a Survivor player is starting to be ridden by a Jockey
 * @remarks This forward will not trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param victim			the client who's being grabbed
 * @param attacker			the Jockey grabbing someone
 *
 * @noreturn
 */
forward void OnJockeyRide_Post(int victim, int attacker);

/**
 * @brief Called whenever CTerrorPlayer::OnLeptOnSurvivor() is invoked
 * @remarks Called when a Survivor player is starting to be ridden by a Jockey
 * @remarks This forward will ONLY trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param victim			the client who's being grabbed
 * @param attacker			the Jockey grabbing someone
 *
 * @noreturn
 */
forward void OnJockeyRide_PostHandled(int victim, int attacker);

/**
 * @brief Called whenever CTerrorPlayer::OnSlammedSurvivor() is invoked
 * @remarks Called when a Survivor is slammed into a wall by a Charger, or on the first pummel if bWallSlam is 0
 * @remarks bDeadlyCharge seems to always return 1 on Windows
 *
 * @param victim			the client who's being slammed
 * @param attacker			the Charger slamming someone
 * @param bWallSlam			when slammed into a wall. Changing this can play a different animation
 * @param bDeadlyCharge		indicates the carry ends at a height down 360.0 units from the carry start, and adds DMG_PARALYZE to the damage flags to incap the victim. Changing this can incap the victim
 *
 * @return					Plugin_Handled to block, Plugin_Changed to use overwritten values from plugin, Plugin_Continue otherwise
 */
forward Action OnSlammedSurvivor(int victim, int attacker, bool &bWallSlam, bool &bDeadlyCharge);

/**
 * @brief Called whenever CTerrorPlayer::OnSlammedSurvivor() is invoked
 * @remarks Called when a Survivor is slammed into a wall by a Charger, or on the first pummel if bWallSlam is 0
 * @bDeadlyCharge seems to always return 1 on Windows
 * @remarks This forward will not trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param victim			the client who's being slammed
 * @param attacker			the Charger slamming someone
 * @param bWallSlam			when slammed into a wall. Changing this can play a different animation
 * @param bDeadlyCharge		indicates the carry ends at a height down 360.0 units from the carry start, and adds DMG_PARALYZE to the damage flags to incap the victim. Changing this can incap the victim
 *
 * @noreturn
 */
forward void OnSlammedSurvivor_Post(int victim, int attacker, bool bWallSlam, bool bDeadlyCharge);

/**
 * @brief Called whenever CTerrorPlayer::OnSlammedSurvivor() is invoked
 * @remarks Called when a Survivor is slammed into a wall by a Charger, or on the first pummel if bWallSlam is 0
 * @bDeadlyCharge seems to always return 1 on Windows
 * @remarks This forward will ONLY trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param victim			the client who's being slammed
 * @param attacker			the Charger slamming someone
 * @param bWallSlam			when slammed into a wall. Changing this can play a different animation
 * @param bDeadlyCharge		indicates the carry ends at a height down 360.0 units from the carry start, and adds DMG_PARALYZE to the damage flags to incap the victim. Changing this can incap the victim
 *
 * @noreturn
 */
forward void OnSlammedSurvivor_PostHandled(int victim, int attacker, bool bWallSlam, bool bDeadlyCharge);

/**
 * @brief Called whenever CTerrorPlayer::OnStartCarryingVictim() is invoked
 * @remarks Called when a Survivor player is about to be carried by a Charger
 *
 * @param victim			the client who's being grabbed
 * @param attacker			the Charger picking up someone
 *
 * @return					Plugin_Handled to block, Plugin_Continue otherwise
 */
forward Action OnStartCarryingVictim(int victim, int attacker);

/**
 * @brief Called whenever CTerrorPlayer::OnStartCarryingVictim() is invoked
 * @remarks Called when a Survivor player is about to be carried by a Charger
 * @remarks This forward will not trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param victim			the client who's being grabbed
 * @param attacker			the Charger picking up someone
 *
 * @noreturn
 */
forward void OnStartCarryingVictim_Post(int victim, int attacker);

/**
 * @brief Called whenever CTerrorPlayer::OnStartCarryingVictim() is invoked
 * @remarks Called when a Survivor player is about to be carried by a Charger
 * @remarks This forward will ONLY trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param victim			the client who's being grabbed
 * @param attacker			the Charger picking up someone
 *
 * @noreturn
 */
forward void OnStartCarryingVictim_PostHandled(int victim, int attacker);

/**
 * @brief Called when CCharge::ImpactStagger is invoked
 * @remarks Called when a Charger impacts a wall or object after charging, but not when carrying a Survivor
 * @remarks Can be used to determine if someone is being staggered from this impact, OnStagger should trigger in the same frame
 *
 * @param client		Client index
 *
 * @noreturn
 **/
forward void OnChargerImpact(int client);

/**
 * @brief Called when CTerrorPlayer::QueuePummelVictim is invoked
 * @remarks Called when a player is about to be pummelled by a Charger
 * @remarks To block the stumble animation and getting stuck inside a Charger see the "OnPummelVictim" section for a demonstration in "left4dhooks_test.sp"
 * @remarks Note: when blocking pummel the Survivor will be stuck inside the Charger (eventually teleporting them) and AI chargers cannot move. See the above demo for a solution
 *
 * @param attacker		Client index of the attacker
 * @param victim		Client index of the victim
 *
 * @return				Plugin_Handled to block pummel, Plugin_Continue to allow
 **/
forward Action OnPummelVictim(int attacker, int victim);

/**
 * @brief Called when CTerrorPlayer::QueuePummelVictim is invoked
 * @remarks Called when a player is about to be pummelled by a Charger
 * @remarks This forward will not trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param attacker		Client index of the attacker
 * @param victim		Client index of the victim
 *
 * @noreturn
 **/
forward void OnPummelVictim_Post(int attacker, int victim);

/**
 * @brief Called when CTerrorPlayer::QueuePummelVictim is invoked
 * @remarks Called when a player is about to be pummelled by a Charger
 * @remarks This forward will ONLY trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param attacker		Client index of the attacker
 * @param victim		Client index of the victim
 *
 * @noreturn
 **/
forward void OnPummelVictim_PostHandled(int attacker, int victim);

/**
 * @brief Called when CTerrorPlayer::IsDominatedBySpecialInfected() is invoked and returned true
 * @remarks Call when a player is being dominated, called over multiple frames
 * @remarks Dominators are: Hunter, Smoker, Jockey, and Charger
 * @remarks This forward is called in frames, but instantly tells you when any domination happened. Recommend not to put too much logic in here
 * @remarks For Chargers, this forward is called when being carried or being pummelled. Queue pummelling will not trigger this forward
 * 
 * @param victim		Client index of the victim
 * @param dominator		Client index of the dominator
 *
 * @noreturn
 **/
forward void OnDominatedBySpecialInfected(int victim, int dominator);

/**
 * @brief Called whenever CTerrorPlayer::OnVomitedUpon is invoked
 * @remarks Called when a Survivor player is covered in Boomer bile, or when using "Bile the World" plugin by "AtomicStryker"
 *
 * @param victim			the client who's now it
 * @param attacker			the attacker who caused the vomit (can be 0)
 * @param boomerExplosion	true if triggered by a boommer explosion
 *
 * @return					Plugin_Handled to block, Plugin_Changed to use overwritten values from plugin, Plugin_Continue otherwise
 */
forward Action OnVomitedUpon(int victim, int &attacker, bool &boomerExplosion);

/**
 * @brief Called whenever CTerrorPlayer::OnVomitedUpon is invoked
 * @remarks Called when a Survivor player is covered in Boomer bile, or when using "Bile the World" plugin by "AtomicStryker"
 * @remarks This forward will not trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param victim			the client who's now it
 * @param attacker			the attacker who caused the vomit (can be 0)
 * @param boomerExplosion	true if triggered by a boommer explosion
 *
 * @noreturn
 */
forward void OnVomitedUpon_Post(int victim, int attacker, bool boomerExplosion);

/**
 * @brief Called whenever CTerrorPlayer::OnVomitedUpon is invoked
 * @remarks Called when a Survivor player is covered in Boomer bile, or when using "Bile the World" plugin by "AtomicStryker"
 * @remarks This forward will ONLY trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param victim			the client who's now it
 * @param attacker			the attacker who caused the vomit (can be 0)
 * @param boomerExplosion	true if triggered by a boommer explosion
 *
 * @noreturn
 */
forward void OnVomitedUpon_PostHandled(int victim, int attacker, bool boomerExplosion);

/**
 * @brief Called whenever CTerrorPlayer::OnHitByVomitJar is invoked
 * @remarks Called when a Special Infected is about to be hit from a Bilejar explosion
 *
 * @param victim			the client who's now it
 * @param attacker			the attacker who caused the vomit (can be 0)
 *
 * @return					Plugin_Handled to block, Plugin_Changed to use overwritten values from plugin, Plugin_Continue otherwise
 */
forward Action OnHitByVomitJar(int victim, int &attacker);

/**
 * @brief Called whenever CTerrorPlayer::OnHitByVomitJar is invoked
 * @remarks Called when a Special Infected is hit from a Bilejar explosion
 * @remarks This forward will not trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param victim			the client who's now it
 * @param attacker			the attacker who caused the vomit (can be 0)
 *
 * @noreturn
 */
forward void OnHitByVomitJar_Post(int victim, int attacker);

/**
 * @brief Called whenever CTerrorPlayer::OnHitByVomitJar is invoked
 * @remarks Called when a Special Infected is hit from a Bilejar explosion
 * @remarks This forward will ONLY trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param victim			the client who's now it
 * @param attacker			the attacker who caused the vomit (can be 0)
 *
 * @noreturn
 */
forward void OnHitByVomitJar_PostHandled(int victim, int attacker);

/**
 * @brief Called whenever Infected::OnHitByVomitJar is invoked
 * @remarks Called when a common infected or Witch is about to be hit from a Bilejar explosion and possibly boomer explosion
 *
 * @param victim			the common who's now it
 * @param attacker			the attacker who caused the vomit (can be 0)
 *
 * @return					Plugin_Handled to block, Plugin_Changed to use overwritten values from plugin, Plugin_Continue otherwise
 */
forward Action Infected_HitByVomitJar(int victim, int &attacker);

/**
 * @brief Called whenever Infected::OnHitByVomitJar is invoked
 * @remarks Called when a common infected or Witch is hit from a Bilejar explosion and possibly boomer explosion
 * @remarks This forward will not trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param victim			the common who's now it
 * @param attacker			the attacker who caused the vomit (can be 0)
 *
 * @noreturn
 */
forward void Infected_HitByVomitJar_Post(int victim, int attacker);

/**
 * @brief Called whenever Infected::OnHitByVomitJar is invoked
 * @remarks Called when a common infected or Witch is hit from a Bilejar explosion and possibly boomer explosion
 * @remarks This forward will ONLY trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param victim			the common who's now it
 * @param attacker			the attacker who caused the vomit (can be 0)
 *
 * @noreturn
 */
forward void Infected_HitByVomitJar_PostHandled(int victim, int attacker);

/**
 * @brief Called whenever CMolotovProjectile::Create is invoked
 * @remarks Called when a Molotov projectile is being created
 *
 * @param client			the client who is throwing the grenade (can be 0)
 * @param vecPos			the position vector of the projectile
 * @param vecAng			the angle vector of the projectile
 * @param vecVel			the velocity vector of the projectile
 * @param vecRot			the rotation vector of the projectile
 *
 * @return					Plugin_Handled to block the grenade creation, Plugin_Changed to modify the vector values, Plugin_Continue otherwise
 */
forward Action MolotovProjectile_Pre(int client, float vecPos[3], float vecAng[3], float vecVel[3], float vecRot[3]);

/**
 * @brief Called whenever CMolotovProjectile::Create is invoked
 * @remarks Called when a Molotov projectile has been created
 * @remarks This forward will not trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param client			the client who is throwing the grenade
 * @param projectile		the projectile entity index (can be 0 if blocked in the pre hook)
 * @param vecPos			the position vector of the projectile
 * @param vecAng			the angle vector of the projectile
 * @param vecVel			the velocity vector of the projectile
 * @param vecRot			the rotation vector of the projectile
 *
 * @noreturn
 */
forward void MolotovProjectile_Post(int client, int projectile, const float vecPos[3], const float vecAng[3], const float vecVel[3], const float vecRot[3]);

/**
 * @brief Called whenever CMolotovProjectile::Create is invoked
 * @remarks Called when a Molotov projectile has been blocked
 * @remarks This forward will ONLY trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param client			the client who is throwing the grenade (can be -1 if blocked)
 * @param projectile		the projectile entity index (can be 0 if blocked in the pre hook)
 * @param vecPos			the position vector of the projectile
 * @param vecAng			the angle vector of the projectile
 * @param vecVel			the velocity vector of the projectile
 * @param vecRot			the rotation vector of the projectile
 *
 * @noreturn
 */
forward void MolotovProjectile_PostHandled(int client, int projectile, const float vecPos[3], const float vecAng[3], const float vecVel[3], const float vecRot[3]);

/**
 * @brief Called whenever CPipeBombProjectile::Create is invoked
 * @remarks Called when a PipeBomb projectile is being created
 *
 * @param client			the client who is throwing the grenade (can be 0)
 * @param vecPos			the position vector of the projectile
 * @param vecAng			the angle vector of the projectile
 * @param vecVel			the velocity vector of the projectile
 * @param vecRot			the rotation vector of the projectile
 *
 * @return					Plugin_Handled to block the grenade creation, Plugin_Changed to modify the vector values, Plugin_Continue otherwise
 */
forward Action PipeBombProjectile_Pre(int client, float vecPos[3], float vecAng[3], float vecVel[3], float vecRot[3]);

/**
 * @brief Called whenever CPipeBombProjectile::Create is invoked
 * @remarks Called when a PipeBomb projectile has been created
 * @remarks This forward will not trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param client			the client who is throwing the grenade
 * @param projectile		the projectile entity index (can be 0 if blocked in the pre hook)
 * @param vecPos			the position vector of the projectile
 * @param vecAng			the angle vector of the projectile
 * @param vecVel			the velocity vector of the projectile
 * @param vecRot			the rotation vector of the projectile
 *
 * @noreturn
 */
forward void PipeBombProjectile_Post(int client, int projectile, const float vecPos[3], const float vecAng[3], const float vecVel[3], const float vecRot[3]);

/**
 * @brief Called whenever CPipeBombProjectile::Create is invoked
 * @remarks Called when a PipeBomb projectile has been blocked
 * @remarks This forward will ONLY trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param client			the client who is throwing the grenade (can be -1 if blocked)
 * @param projectile		the projectile entity index (can be 0 if blocked in the pre hook)
 * @param vecPos			the position vector of the projectile
 * @param vecAng			the angle vector of the projectile
 * @param vecVel			the velocity vector of the projectile
 * @param vecRot			the rotation vector of the projectile
 *
 * @noreturn
 */
forward void PipeBombProjectile_PostHandled(int client, int projectile, const float vecPos[3], const float vecAng[3], const float vecVel[3], const float vecRot[3]);

/**
 * @brief Called whenever CVomitJarProjectile::Create is invoked
 * @remarks Called when a VomitJar projectile is being created
 *
 * @param client			the client who is throwing the grenade (can be 0)
 * @param vecPos			the position vector of the projectile
 * @param vecAng			the angle vector of the projectile
 * @param vecVel			the velocity vector of the projectile
 * @param vecRot			the rotation vector of the projectile
 *
 * @return					Plugin_Handled to block the grenade creation, Plugin_Changed to modify the vector values, Plugin_Continue otherwise
 */
forward Action VomitJarProjectile_Pre(int client, float vecPos[3], float vecAng[3], float vecVel[3], float vecRot[3]);

/**
 * @brief Called whenever CVomitJarProjectile::Create is invoked
 * @remarks Called when a VomitJar projectile has been created
 * @remarks This forward will not trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param client			the client who is throwing the grenade
 * @param projectile		the projectile entity index (can be 0 if blocked in the pre hook)
 * @param vecPos			the position vector of the projectile
 * @param vecAng			the angle vector of the projectile
 * @param vecVel			the velocity vector of the projectile
 * @param vecRot			the rotation vector of the projectile
 *
 * @noreturn
 */
forward void VomitJarProjectile_Post(int client, int projectile, const float vecPos[3], const float vecAng[3], const float vecVel[3], const float vecRot[3]);

/**
 * @brief Called whenever CVomitJarProjectile::Create is invoked
 * @remarks Called when a VomitJar projectile has been blocked
 * @remarks This forward will ONLY trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param client			the client who is throwing the grenade (can be -1 if blocked)
 * @param projectile		the projectile entity index (can be 0 if blocked in the pre hook)
 * @param vecPos			the position vector of the projectile
 * @param vecAng			the angle vector of the projectile
 * @param vecVel			the velocity vector of the projectile
 * @param vecRot			the rotation vector of the projectile
 *
 * @noreturn
 */
forward void VomitJarProjectile_PostHandled(int client, int projectile, const float vecPos[3], const float vecAng[3], const float vecVel[3], const float vecRot[3]);

/**
 * @brief Called whenever CGrenadeLauncher_Projectile::Create is invoked
 * @remarks Called when a Grenade Launcher projectile is being created
 *
 * @param client			the client who is shooting the grenade launcher projectile (can be 0)
 * @param vecPos			the position vector of the projectile
 * @param vecAng			the angle vector of the projectile
 * @param vecVel			the velocity vector of the projectile
 * @param vecRot			the rotation vector of the projectile
 *
 * @return					Plugin_Handled to block the grenade creation, Plugin_Changed to modify the vector values and incendiary flag, Plugin_Continue otherwise
 */
forward Action GrenadeLauncherProjectile_Pre(int client, float vecPos[3], float vecAng[3], float vecVel[3], float vecRot[3], bool &bIncendiary);

/**
 * @brief Called whenever CGrenadeLauncher_Projectile::Create is invoked
 * @remarks Called when a Grenade Launcher projectile has been created
 * @remarks This forward will not trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param client			the client who is shooting the grenade launcher projectile
 * @param projectile		the projectile entity index (can be 0 if blocked in the pre hook)
 * @param vecPos			the position vector of the projectile
 * @param vecAng			the angle vector of the projectile
 * @param vecVel			the velocity vector of the projectile
 * @param vecRot			the rotation vector of the projectile
 *
 * @noreturn
 */
forward void GrenadeLauncherProjectile_Post(int client, int projectile, const float vecPos[3], const float vecAng[3], const float vecVel[3], const float vecRot[3], bool bIncendiary);

/**
 * @brief Called whenever CGrenadeLauncher_Projectile::Create is invoked
 * @remarks Called when a Grenade Launcher projectile has been blocked
 * @remarks This forward will ONLY trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param client			the client who is shooting the grenade launcher projectile (can be -1 if blocked)
 * @param projectile		the projectile entity index (can be 0 if blocked in the pre hook)
 * @param vecPos			the position vector of the projectile
 * @param vecAng			the angle vector of the projectile
 * @param vecVel			the velocity vector of the projectile
 * @param vecRot			the rotation vector of the projectile
 *
 * @noreturn
 */
forward void GrenadeLauncherProjectile_PostHandled(int client, int projectile, const float vecPos[3], const float vecAng[3], const float vecVel[3], const float vecRot[3], bool bIncendiary);

/**
 * @brief Called whenever CMolotovProjectile::Detonate is invoked
 * @remarks Called when a Molotov projectile is about to explode
 *
 * @param entity			the entity that exploded
 * @param client			the client who threw the grenade, can be -1
 *
 * @return					Plugin_Handled to block explosion which will cause the Molotov projectile to bounce remain active, Plugin_Continue otherwise
 */
forward Action Molotov_Detonate(int entity, int client);

/**
 * @brief Called whenever CMolotovProjectile::Detonate is invoked
 * @remarks Called when a Molotov projectile has exploded
 * @remarks This forward will not trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param entity			the entity that exploded
 * @param client			the client who threw the grenade, can be -1
 *
 * @noreturn
 */
forward void Molotov_Detonate_Post(int entity, int client);

/**
 * @brief Called whenever CMolotovProjectile::Detonate is invoked
 * @remarks Called when a Molotov projectile explosion was prevented
 * @remarks This forward will ONLY trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param entity			the entity that exploded
 * @param client			the client who threw the grenade, can be -1
 *
 * @noreturn
 */
forward void Molotov_Detonate_PostHandled(int entity, int client);

/**
 * @brief Called whenever CPipeBombProjectile::Detonate is invoked
 * @remarks Called when a PipeBomb projectile (or possibly a breakable prop, see include file notes below) is about to explode
 *
 * @note This forward is also called when a breakable prop (propane tank, oxygen tank etc) is breaking, to detect pipebomb only you should:
 * @note Use the "PipeBombProjectile_Post" forward and store GetGameTime() with the projectile entity index
 * @note Then within this forward compare the current GetGameTime() with the one stored for the entity
 * @note If the times do not match then a PipeBomb has exploded, if the times match then a breakable prop has exploded
 *
 * @param entity			the entity that exploded
 * @param client			the client who threw the grenade, can be -1
 *
 * @return					Plugin_Handled to block explosion which will cause the PipeBomb projectile to continue flashing and remain active, Plugin_Continue otherwise
 */
forward Action PipeBomb_Detonate(int entity, int client);

/**
 * @brief Called whenever CPipeBombProjectile::Detonate is invoked
 * @remarks Called when a PipeBomb projectile (or possibly a breakable prop, see include file notes below) has exploded
 * @remarks This forward will not trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @note This forward is also called when a breakable prop (propane tank, oxygen tank etc) is breaking, to detect pipebomb only you should:
 * @note Use the "PipeBombProjectile_Post" forward and store GetGameTime() with the projectile entity index
 * @note Then within this forward compare the current GetGameTime() with the one stored for the entity
 * @note If the times do not match then a PipeBomb has exploded, if the times match then a breakable prop has exploded
 *
 * @param entity			the entity that exploded
 * @param client			the client who threw the grenade, can be -1
 *
 * @noreturn
 */
forward void PipeBomb_Detonate_Post(int entity, int client);

/**
 * @brief Called whenever CPipeBombProjectile::Detonate is invoked
 * @remarks Called when a PipeBomb projectile explosion (or possibly a breakable prop, see include file notes below) was prevented
 * @remarks This forward will ONLY trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param entity			the entity that exploded
 * @param client			the client who threw the grenade, can be -1
 *
 * @noreturn
 */
forward void PipeBomb_Detonate_PostHandled(int entity, int client);

/**
 * @brief Called whenever CVomitJarProjectile::Detonate is invoked
 * @remarks Called when a VomitJar projectile is about to explode
 *
 * @param entity			the entity that exploded
 * @param client			the client who threw the grenade, can be -1
 *
 * @return					Plugin_Handled to block explosion which will cause the Vomitjar projectile to bounce and remain active, Plugin_Continue otherwise
 */
forward Action VomitJar_Detonate(int entity, int client);

/**
 * @brief Called whenever CVomitJarProjectile::Detonate is invoked
 * @remarks Called when a VomitJar projectile has exploded
 * @remarks This forward will not trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param entity			the entity that exploded
 * @param client			the client who threw the grenade, can be -1
 *
 * @noreturn
 */
forward void VomitJar_Detonate_Post(int entity, int client);

/**
 * @brief Called whenever CVomitJarProjectile::Detonate is invoked
 * @remarks Called when a VomitJar projectile explosion was prevented
 * @remarks This forward will ONLY trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param entity			the entity that exploded
 * @param client			the client who threw the grenade, can be -1
 *
 * @noreturn
 */
forward void VomitJar_Detonate_PostHandled(int entity, int client);

/**
 * @brief Called whenever CGrenadeLauncher_Projectile::Explode is invoked
 * @remarks Called when a Grenade Launcher projectile is about to explode
 *
 * @param entity			the entity that exploded
 * @param client			the client who shot the grenade, can be -1
 *
 * @return					Plugin_Handled to block explosion which will cause the Grenade Launcher projectile to bounce and remain active, Plugin_Continue otherwise
 */
forward Action GrenadeLauncher_Detonate(int entity, int client);

/**
 * @brief Called whenever CGrenadeLauncher_Projectile::Explode is invoked
 * @remarks Called when a Grenade Launcher projectile has exploded
 * @remarks This forward will not trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param entity			the entity that exploded
 * @param client			the client who shot the grenade, can be -1
 *
 * @noreturn
 */
forward void GrenadeLauncher_Detonate_Post(int entity, int client);

/**
 * @brief Called whenever CGrenadeLauncher_Projectile::Explode is invoked
 * @remarks Called when a Grenade Launcher projectile explosion was prevented
 * @remarks This forward will ONLY trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param entity			the entity that exploded
 * @param client			the client who shot the grenade, can be -1
 *
 * @noreturn
 */
forward void GrenadeLauncher_Detonate_PostHandled(int entity, int client);

/**
 * @brief Called whenever CInsectSwarm::CanHarm() is invoked
 * @remarks Called when Spitter Acid is determining if a client or entity can be damaged
 *
 * @param acid				the acid entity index causing the damage
 * @param spitter			the Spitter or client who created the acid (can be 0 or -1)
 * @param entity			the client or entity index being checked if it can be damaged
 *
 * @return					Plugin_Handled to block allowing damage to an entity, Plugin_Continue otherwise
 */
forward Action CInsectSwarm_CanHarm(int acid, int spitter, int entity);

/**
 * @brief Called whenever CInsectSwarm::CanHarm() is invoked
 * @remarks Called when Spitter Acid has determining if a client or entity can be damaged, or not called when block in the pre forward
 * @remarks This forward will not trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param acid				the acid entity index causing the damage
 * @param spitter			the Spitter or client who created the acid (can be 0 or -1)
 * @param entity			the client or entity index being checked if it can be damaged
 *
 * @noreturn
 */
forward void CInsectSwarm_CanHarm_Post(int acid, int spitter, int entity);

/**
 * @brief Called whenever CInsectSwarm::CanHarm() is invoked
 * @remarks Called when Spitter Acid has determining if a client or entity can be damaged
 * @remarks This forward will ONLY trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param acid				the acid entity index causing the damage
 * @param spitter			the Spitter or client who created the acid (can be 0 or -1)
 * @param entity			the client or entity index being checked if it can be damaged
 *
 * @noreturn
 */
forward void CInsectSwarm_CanHarm_PostHandled(int acid, int spitter, int entity);

/**
 * @brief Called whenever CBreakableProp::Break() is invoked
 * @remarks Called when a physics prop is broken
 * @note When a propanetank explodes, it will create and explode another prop_physics and the attacker entity will be 0. Maybe only L4D2 has this issue
 *
 * @param prop				the physics entity index which broke
 * @param entity			the client or entity who caused the prop to break (could be 0)
 *
 * @noreturn
 */
forward void CBreakableProp_Break(int prop, int entity);

/**
 * @brief Called whenever CTerrorPlayer::StartUseAction() is invoked
 * @remarks Called when a player is holding an item and about to use it
 *
 * @param action			the type of action being performed (can use the "L4D2UseAction" enum from "left4dhooks_stocks.inc" include file)
 * @param client			the client performing the action
 * @param target			the target they are affecting/using
 *
 * @return					Plugin_Handled to block action, Plugin_Continue otherwise
 */
forward Action OnStartUseAction(any action, int client, int target);

/**
 * @brief Called whenever CTerrorPlayer::StartUseAction() is invoked
 * @remarks Called when a player is holding an item and about to use it
 * @remarks The target entity will appear as the client when deploying upgrade packs
 * @remarks This forward will not trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param action			the type of action being performed (can use the "L4D2UseAction" enum from "left4dhooks_stocks.inc" include file)
 * @param client			the client performing the action
 * @param target			the target they are affecting/using
 *
 * @noreturn
 */
forward void OnStartUseAction_Post(any action, int client, int target);

/**
 * @brief Called whenever CTerrorPlayer::StartUseAction() is invoked
 * @remarks Called when a player is holding an item and about to use it
 * @remarks This forward will ONLY trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param action			the type of action being performed (can use the "L4D2UseAction" enum from "left4dhooks_stocks.inc" include file)
 * @param client			the client performing the action
 * @param target			the target they are affecting/using
 *
 * @noreturn
 */
forward void OnStartUseAction_PostHandled(any action, int client, int target);

/**
 * @brief Called whenever CBaseBackpackItem::StartAction() is invoked
 * @remarks Called when a player is holding an item and about to use it
 * @note: This does not change the animation speed
 * @note: Detouring as a pre-hook for changing the following per player before starting any actions:
 * - "first_aid_kit_use_duration"
 * - "ammo_pack_use_duration"
 * - "cola_bottles_use_duration"
 * - "defibrillator_use_duration"
 * - "gas_can_use_duration"
 * - "upgrade_pack_use_duration"
 * @note: Detouring as a post-hook for changing the above back to default values after starting any actions
 * @note: To find the use entity that is being targeted, use the native: "FindUseEntity"
 *
 * @param client			the client performing the action
 * @param entity			the entity they are using
 * @param type				the weapon type ID. Can be found as L4D2WeaponId in the left4dhooks_stocks include file
 *
 * @return					Plugin_Handled to block healing, Plugin_Continue otherwise
 */
forward Action BackpackItem_StartAction(int client, int entity, any type);

/**
 * @brief Called whenever CBaseBackpackItem::StartAction() is invoked
 * @remarks Called when a player is holding an item and about to use it
 * @remarks This forward will not trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 * @note: This does not change the animation speed
 * @note: Detouring as a pre-hook for changing the following per player before starting any actions:
 * - "first_aid_kit_use_duration"
 * - "ammo_pack_use_duration"
 * - "cola_bottles_use_duration"
 * - "defibrillator_use_duration"
 * - "gas_can_use_duration"
 * - "upgrade_pack_use_duration"
 * @note: Detouring as a post-hook for changing the above back to default values after starting any actions
 * @note: To find the use entity that is being targeted, use the native: "FindUseEntity"
 *
 * @param client			the client performing the action
 * @param entity			the entity they are using
 * @param type				the weapon type ID. Can be found as L4D2WeaponId in the left4dhooks_stocks include file
 *
 * @noreturn
 */
forward void BackpackItem_StartAction_Post(int client, int entity, any type);

/**
 * @brief Called whenever CBaseBackpackItem::StartAction() is invoked
 * @remarks Called when a player is holding an item and about to use it
 * @remarks This forward will ONLY trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 * @note: This does not change the animation speed
 * @note: Detouring as a pre-hook for changing the following per player before starting any actions:
 * - "first_aid_kit_use_duration"
 * - "ammo_pack_use_duration"
 * - "cola_bottles_use_duration"
 * - "defibrillator_use_duration"
 * - "gas_can_use_duration"
 * - "upgrade_pack_use_duration"
 * @note: Detouring as a post-hook for changing the above back to default values after starting any actions
 * @note: To find the use entity that is being targeted, use the native: "FindUseEntity"
 *
 * @param client			the client performing the action
 * @param entity			the entity they are using
 * @param type				the weapon type ID. Can be found as L4D2WeaponId in the left4dhooks_stocks include file
 *
 * @noreturn
 */
forward void BackpackItem_StartAction_PostHandled(int client, int entity, any type);

/**
 * @brief Called whenever CGasCan::Event_Killed() is invoked
 * @remarks Called when a gascan is broken
 *
 * @param gascan			the gascan entity index
 * @param inflictor			the inflictor entity index
 * @param attacker			the attacker entity index
 *
 * @return					Plugin_Handled to block detonating, Plugin_Changed to change any values, Plugin_Continue otherwise
 */
forward Action CGasCan_EventKilled(int gascan, int &inflictor, int &attacker);

/**
 * @brief Called whenever CGasCan::Event_Killed() is invoked
 * @remarks Called when a gascan is broken
 *
 * @param gascan			the gascan entity index
 * @param inflictor			the inflictor entity index
 * @param attacker			the attacker entity index
 *
 * @noreturn
 */
forward void CGasCan_EventKilled_Post(int gascan, int inflictor, int attacker);

/**
 * @brief Called whenever CGasCan::Event_Killed() is invoked
 * @remarks Called when a gascan is broken
 *
 * @param gascan			the gascan entity index
 * @param inflictor			the inflictor entity index
 * @param attacker			the attacker entity index
 *
 * @noreturn
 */
forward void CGasCan_EventKilled_PostHandled(int gascan, int inflictor, int attacker);

/**
 * @brief Called whenever CGasCan::ShouldStartAction() is invoked
 * @remarks Called when someone is about to pour a gascan into a nozzle
 *
 * @param client			the client pouring
 * @param gascan			the gascan entity index that is being consumed
 * @param nozzle			the nozzle being poured into
 *
 * @return					Plugin_Handled to block adding to Scavenge score (see "Scavenge Score Fix" plugin for more details), Plugin_Continue otherwise
 */
forward Action CGasCan_ShouldStartAction(int client, int gascan, int nozzle);

/**
 * @brief Called whenever CGasCan::ShouldStartAction() is invoked
 * @remarks Called when someone has started to pour a gascan into a nozzle
 * @remarks This forward will not trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param client			the client pouring
 * @param gascan			the gascan entity index that is being consumed
 * @param nozzle			the nozzle being poured into
 *
 * @noreturn
 */
forward void CGasCan_ShouldStartAction_Post(int client, int gascan, int nozzle);

/**
 * @brief Called whenever CGasCan::ShouldStartAction() is invoked
 * @remarks Called when someone has started to pour a gascan into a nozzle
 * @remarks This forward will ONLY trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param client			the client pouring
 * @param gascan			the gascan entity index that is being consumed
 * @param nozzle			the nozzle being poured into
 *
 * @noreturn
 */
forward void CGasCan_ShouldStartAction_PostHandled(int client, int gascan, int nozzle);

/**
 * @brief Called whenever CGasCan::OnActionComplete() is invoked
 * @remarks Called when someone is about to complete pouring a gascan into a nozzle
 *
 * @param client			the client pouring
 * @param gascan			the gascan entity index that is being consumed
 * @param nozzle			the nozzle being poured into
 *
 * @return					Plugin_Handled to block adding to Scavenge score (see "Scavenge Score Fix" plugin for more details), Plugin_Continue otherwise
 */
forward Action CGasCan_ActionComplete(int client, int gascan, int nozzle);

/**
 * @brief Called whenever CGasCan::OnActionComplete() is invoked
 * @remarks Called when someone completes pouring a gascan into a nozzle
 * @remarks This forward will not trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param client			the client pouring
 * @param gascan			the gascan entity index that is being consumed
 * @param nozzle			the nozzle being poured into
 *
 * @noreturn
 */
forward void CGasCan_ActionComplete_Post(int client, int gascan, int nozzle);

/**
 * @brief Called whenever CGasCan::OnActionComplete() is invoked
 * @remarks Called when someone completes pouring a gascan into a nozzle
 * @remarks This forward will ONLY trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 *
 * @param client			the client pouring
 * @param gascan			the gascan entity index that is being consumed
 * @param nozzle			the nozzle being poured into
 *
 * @noreturn
 */
forward void CGasCan_ActionComplete_PostHandled(int client, int gascan, int nozzle);

/**
 * @brief Returns the current game mode type when it changes. 0=Unknown or error. 1=Coop. 2=Versus. 4=Survival. 8=Scavenge (L4D2)
 * @remarks You can use the "GAMEMODE_*" enums provided above to match the mode
 * @remarks Only triggers when the server starts and after when the game mode changes
 *
 * @param gamemode		Current game mode
 *
 * @noreturn
 */
forward void OnGameModeChange(int gamemode);

/**
 * @brief Called when the server changes hibernation status
 *
 * @param hibernating		true when hibernating, false when waking up
 *
 * @noreturn
 */
forward void OnServerHibernationUpdate(bool hibernating);

/**
 * @brief Called whenever InfoChangelevel::SaveEntities() is invoked
 * @brief Called when a map has been finished, and is about to save the entities in the saferoom (usually props or items brought into the saferoom.)
 * @remarks Called before the event "map_transition"
 * @remarks Won't be called if CTerrorGameRules::HasPlayerControlledZombies() returns true, which refers to the versus/scavenge related pvp gamemode
 * 
 * @param info_changelevel	The entity index of "info_changelevel"
 * 
 * @return					Plugin_Handled to prevent saving entities, Plugin_Continue otherwise
*/
forward Action OnSavingEntities(int info_changelevel);

/**
 * @brief Called whenever InfoChangelevel::SaveEntities() is invoked
 * @brief Called when a map has been finished, and the game has finished saving the entities in the saferoom
 * @remarks Called before the event "map_transition"
 * @remarks Won't be called if CTerrorGameRules::HasPlayerControlledZombies() returns true, which refers to the versus/scavenge related pvp gamemode
 * @remarks This forward will not trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 * 
 * @param info_changelevel	The entity index of "info_changelevel"
 * 
 * @noreturn
*/
forward void OnSavingEntities_Post(int info_changelevel);

/**
 * @brief Called whenever InfoChangelevel::SaveEntities() is invoked
 * @brief Called when a map has been finished, and the game has finished saving the entities in the saferoom
 * @remarks Called before the event "map_transition"
 * @remarks Won't be called if CTerrorGameRules::HasPlayerControlledZombies() returns true, which refers to the versus/scavenge related pvp gamemode
 * @remarks This forward will ONLY trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 * 
 * @param info_changelevel	The entity index of "info_changelevel"
 * 
 * @noreturn
*/
forward void OnSavingEntities_PostHandled(int info_changelevel);

/**
 * Internally, game uses keyvalues structure to save survivors' data for the level-transitioning,
 * and stores these keyvalues into an array.
 * After we have transitioned to the next map, we restore the data from the keyvalues array.
 * 
 * To retrieve the keyvalues before these functions below calling,
 * you may need to access the memory from the internal global array g_SavedPlayers or g_SavedSurvivorBots etc.
 * 
 * To see the keys and their values, see PlayerSaveData::PlayerSaveData().
*/

/**
 * @brief Called whenever CTerrorPlayer::TransitionRestore is invoked.
 * @remarks This will only be called for human players after the level-transitioning. For bots, See OnRestoreTransitionedSurvivorBots.
 * @remarks This will be called for every survivors including bots once the level failed and restarted.
 * 
 * @param client		Client index
 * 
 * @return				Plugin_Handled to block this player from restoring their level-transitioned data, others otherwise.
*/
forward Action OnTransitionRestore(int client);

/**
 * @brief Called after CTerrorPlayer::TransitionRestore is invoked.
 * @remarks This will only be called for human players after the level-transitioning. For bots, See OnRestoreTransitionedSurvivorBots.
 * @remarks This will be called for every survivors including bots once the level failed and restarted.
 * @remarks This forward will not trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 * 
 * @param client		Client index
 * @param pkv			Address of the keyvalues pointer.
 * 
 * @noreturn
*/
forward void OnTransitionRestore_Post(int client, Address pkv);

/**
 * @brief Called after CTerrorPlayer::TransitionRestore is invoked.
 * @remarks This will only be called for human players after the level-transitioning. For bots, See OnRestoreTransitionedSurvivorBots.
 * @remarks This will be called for every survivors including bots once the level failed and restarted.
 * @remarks This forward will ONLY trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 * 
 * @param client		Client index
 * @param pkv			Address of the keyvalues pointer.
 * 
 * @noreturn
*/
forward void OnTransitionRestore_PostHandled(int client, Address pkv);

/**
 * @brief Called after RestoreTransitionedSurvivorBots is invoked. Called BEFORE bots create.
 * 
 * @remarks This will only be called once after the level-transitioning and will not be called once the level failed.
 * @remarks Blocking this function will result the bot not being spawned after transitioned to next map.
 * @remarks For human players, See OnTransitionRestore.
 * 
 * @param botIndex		Bot index
 * 
 * @return				Plugin_Handled to block this bot from being created, others otherwise.
*/
forward Action OnRestoreTransitionedSurvivorBots();

/**
 * @brief Called after RestoreTransitionedSurvivorBots is invoked. Called AFTER bots have created.
 * 
 * @remarks This will only be called once after the level-transitioning and will not be called once the level failed.
 * @remarks For human players, See OnTransitionRestore.
 * @remarks This forward will ONLY trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 * 
 * @noreturn
*/
forward void OnRestoreTransitionedSurvivorBots_Post();

/**
 * @brief Called after RestoreTransitionedSurvivorBots is invoked. Called AFTER bots have created.
 * 
 * @remarks This will only be called once after the level-transitioning and will not be called once the level failed.
 * @remarks For human players, See OnTransitionRestore.
 * @remarks This forward will not trigger if the relative pre-hook forward has been blocked with Plugin_Handled
 * 
 * @noreturn
*/
forward void OnRestoreTransitionedSurvivorBots_PostHandled();

/**
 * @brief Called when the client's material system is expecting instructions from the server in regards to addons
 * @remarks Doesn't fire if addons_eclipse is -1 or 0
 *
 * @param SteamID	SteamID of the client expecting a matsys reply
 *
 * @return			Plugin_Handled to let the client through with addons, Plugin_Continue otherwise
 */
forward Action OnClientDisableAddons(const char[] SteamID);

// ====================================================================================================
// NATIVES - l4d2weapons.inc
// ====================================================================================================

enum L4D2IntWeaponAttributes {
	L4D2IWA_Damage,
	L4D2IWA_Bullets,
	L4D2IWA_ClipSize,
	L4D2IWA_Bucket,
	L4D2IWA_Tier,
	L4D2IWA_DefaultSize,	// Default weapon clip size
	L4D2IWA_WeaponType,		// Can use with the "WeaponType" enum
	MAX_SIZE_L4D2IntWeaponAttributes
};

enum L4D2FloatWeaponAttributes {
	L4D2FWA_MaxPlayerSpeed,
	L4D2FWA_SpreadPerShot,
	L4D2FWA_MaxSpread,
	L4D2FWA_SpreadDecay,
	L4D2FWA_MinDuckingSpread,
	L4D2FWA_MinStandingSpread,
	L4D2FWA_MinInAirSpread,
	L4D2FWA_MaxMovementSpread,
	L4D2FWA_PenetrationNumLayers,
	L4D2FWA_PenetrationPower,
	L4D2FWA_PenetrationMaxDist,
	L4D2FWA_CharPenetrationMaxDist,
	L4D2FWA_Range,
	L4D2FWA_RangeModifier,
	L4D2FWA_CycleTime,
	L4D2FWA_PelletScatterPitch,
	L4D2FWA_PelletScatterYaw,
	L4D2FWA_VerticalPunch,
	L4D2FWA_HorizontalPunch, // Requires "z_gun_horiz_punch" cvar changed to "1" - maybe not, read/write might work fine without
	L4D2FWA_GainRange,
	L4D2FWA_ReloadDuration,
	MAX_SIZE_L4D2FloatWeaponAttributes
};

enum L4D2BoolMeleeWeaponAttributes
{
	L4D2BMWA_Decapitates,
	MAX_SIZE_L4D2BoolMeleeWeaponAttributes
};

enum L4D2IntMeleeWeaponAttributes
{
	L4D2IMWA_DamageFlags,
	L4D2IMWA_RumbleEffect,
	MAX_SIZE_L4D2IntMeleeWeaponAttributes
};

enum L4D2FloatMeleeWeaponAttributes
{
	L4D2FMWA_Damage,
	L4D2FMWA_RefireDelay,
	L4D2FMWA_WeaponIdleTime,
	MAX_SIZE_L4D2FloatMeleeWeaponAttributes
};

enum /*WeaponId*/
{
	WEPID_NONE,             // 0
	WEPID_PISTOL,           // 1
	WEPID_SMG,              // 2
	WEPID_PUMPSHOTGUN,      // 3
	WEPID_AUTOSHOTGUN,      // 4
	WEPID_RIFLE,            // 5
	WEPID_HUNTING_RIFLE,    // 6
	WEPID_SMG_SILENCED,     // 7
	WEPID_SHOTGUN_CHROME,   // 8
	WEPID_RIFLE_DESERT,     // 9
	WEPID_SNIPER_MILITARY,  // 10
	WEPID_SHOTGUN_SPAS,     // 11
	WEPID_FIRST_AID_KIT,    // 12
	WEPID_MOLOTOV,          // 13
	WEPID_PIPE_BOMB,        // 14
	WEPID_PAIN_PILLS,       // 15
	WEPID_GASCAN,           // 16
	WEPID_PROPANE_TANK,     // 17
	WEPID_OXYGEN_TANK,      // 18
	WEPID_MELEE,            // 19
	WEPID_CHAINSAW,         // 20
	WEPID_GRENADE_LAUNCHER, // 21
	WEPID_AMMO_PACK,        // 22
	WEPID_ADRENALINE,       // 23
	WEPID_DEFIBRILLATOR,    // 24
	WEPID_VOMITJAR,         // 25
	WEPID_RIFLE_AK47,       // 26
	WEPID_GNOME_CHOMPSKI,   // 27
	WEPID_COLA_BOTTLES,     // 28
	WEPID_FIREWORKS_BOX,    // 29
	WEPID_INCENDIARY_AMMO,  // 30
	WEPID_FRAG_AMMO,        // 31
	WEPID_PISTOL_MAGNUM,    // 32
	WEPID_SMG_MP5,          // 33
	WEPID_RIFLE_SG552,      // 34
	WEPID_SNIPER_AWP,       // 35
	WEPID_SNIPER_SCOUT,     // 36
	WEPID_RIFLE_M60,        // 37
	WEPID_TANK_CLAW,        // 38
	WEPID_HUNTER_CLAW,      // 39
	WEPID_CHARGER_CLAW,     // 40
	WEPID_BOOMER_CLAW,      // 41
	WEPID_SMOKER_CLAW,      // 42
	WEPID_SPITTER_CLAW,     // 43
	WEPID_JOCKEY_CLAW,      // 44
	WEPID_MACHINEGUN,       // 45
	WEPID_VOMIT,            // 46
	WEPID_SPLAT,            // 47
	WEPID_POUNCE,           // 48
	WEPID_LOUNGE,           // 49
	WEPID_PULL,             // 50
	WEPID_CHOKE,            // 51
	WEPID_ROCK,             // 52
	WEPID_PHYSICS,          // 53
	WEPID_AMMO,             // 54
	WEPID_UPGRADE_ITEM,     // 55

	WEPID_SIZE //56 size
};

enum L4D2CountdownTimer
{
	L4D2CT_MobSpawnTimer,
	L4D2CT_SmokerSpawnTimer,
	L4D2CT_BoomerSpawnTimer,
	L4D2CT_HunterSpawnTimer,
	L4D2CT_SpitterSpawnTimer,
	L4D2CT_JockeySpawnTimer,
	L4D2CT_ChargerSpawnTimer,
	L4D2CT_VersusStartTimer,
	L4D2CT_UpdateMarkersTimer,
	L4D2CT_SurvivalSetupTimer
};

enum L4D2IntervalTimer
{
	L4D2IT_SmokerDeathTimer,
	L4D2IT_BoomerDeathTimer,
	L4D2IT_HunterDeathTimer,
	L4D2IT_SpitterDeathTimer,
	L4D2IT_JockeyDeathTimer,
	L4D2IT_ChargerDeathTimer
};

enum CountdownTimer
{
	CTimer_Null = 0 /*< Invalid Timer when lookup fails */
};

enum IntervalTimer
{
	ITimer_Null = 0 /*< Invalid Timer when lookup fails */
};
// Used by "CommandABot" native:
enum BOT_CMD
{
	BOT_CMD_ATTACK = 0,		// Force the bot to attack a specific target, even bypassing CTerrorPlayer::SetSenseFlags (DirectorScript.BOT_CANT_SEE)
	BOT_CMD_MOVE = 1,		// Force the bot to move to a specific location, which then they will do it unconditionally without performing any other AI behaviours controlled by themselves
							// This means that Survivor Bots and most player-controllable Special Infected won't attack anything when commanded, but Common Infected still automatically attack enemies if they close in enough
	BOT_CMD_RETREAT = 2,	// Force the bot to retreat from a target entity. Only works when used on Survivor Bots, and if target is a Tank
	BOT_CMD_RESET = 3		// Removes the active bot command and lets the AI resume controlling the bot
};

// Some of these will only be valid after OnMapStart() because they change on each new map. For example: POINTER_GAMERULES, POINTER_THENAVAREAS, POINTER_MISSIONINFO and possibly others
enum PointerType
{
	POINTER_DIRECTOR		= 1,	// @TheDirector
	POINTER_SERVER			= 2,	// @sv
	POINTER_GAMERULES		= 3,	// @g_pGameRules
	POINTER_NAVMESH			= 4,	// @TheNavMesh
	POINTER_ZOMBIEMANAGER	= 5,	// @TheZombieManager
	POINTER_WEAPONINFO		= 6,	// @_ZL20m_WeaponInfoDatabase
	POINTER_MELEEINFO		= 7,	// @g_MeleeWeaponInfoStore (L4D2 Only)
	POINTER_EVENTMANAGER	= 8,	// pScriptedEventManager (L4D2 Only)
	POINTER_SCAVENGEMODE	= 9,	// pScavengeMode (L4D2 Only)
	POINTER_VERSUSMODE		= 10,	// pVersusMode
	POINTER_SCRIPTVM		= 11,	// @g_pScriptVM (L4D2 Only)
	POINTER_THENAVAREAS		= 12,	// @TheNavAreas
	POINTER_MISSIONINFO		= 13,	// MissionInfo pointer
	POINTER_SURVIVALMODE	= 14,	// pSurvivalMode pointer (assuming this is the same as pVersusMode in L4D1 and also TheDirector)
	POINTER_AMMODEF			= 15,	// ammoDef Pointer
	POINTER_ITEMMANAGER		= 16,	// pItemManager (L4D2 Only)
	POINTER_MUSICBANKS		= 17,	// pMusicBanks (L4D2 Only)
	POINTER_SESSIONMANAGER	= 18,	// pSessionManager (L4D2 Only)
	POINTER_CHALLENGEMODE	= 19	// pChallengeMode (L4D2 Only) (mutation modes)
};

// From: https://developer.valvesoftware.com/wiki/List_of_L4D_Series_Nav_Mesh_Attributes
// Use by "GetNavAreaAttributeFlags" and "SetNavAreaAttributeFlags" natives
// NavArea Base Attributes:
enum {
	NAV_BASE_CROUCH = 1,							// (1<<0)
	NAV_BASE_JUMP = 2,								// (1<<1)
	NAV_BASE_PRECISE = 4,							// (1<<2)
	NAV_BASE_NO_JUMP = 8,							// (1<<3)
	NAV_BASE_STOP = 16,								// (1<<4)
	NAV_BASE_RUN = 32,								// (1<<5)
	NAV_BASE_WALK = 64,								// (1<<6)
	NAV_BASE_AVOID = 128,							// (1<<7)
	NAV_BASE_TRANSIENT = 256,						// (1<<8)
	NAV_BASE_DONT_HIDE = 512,						// (1<<9)
	NAV_BASE_STAND = 1024,							// (1<<10)
	NAV_BASE_NO_HOSTAGES = 2048,					// (1<<11)
	NAV_BASE_STAIRS = 4096,							// (1<<12)
	NAV_BASE_NO_MERGE = 8192,						// (1<<13)
	NAV_BASE_OBSTACLE_TOP = 16384,					// (1<<14)
	NAV_BASE_CLIFF = 32768,							// (1<<15)
	NAV_BASE_TANK_ONLY = 65536,						// (1<<16)
	NAV_BASE_MOB_ONLY = 131072,						// (1<<17)
	NAV_BASE_PLAYERCLIP = 262144,					// (1<<18)
	NAV_BASE_BREAKABLEWALL = 524288,				// (1<<19)
	NAV_BASE_FLOW_BLOCKED = 134217728,				// (1<<27)
	NAV_BASE_OUTSIDE_WORLD = 268435456,				// (1<<28)
	NAV_BASE_MOSTLY_FLAT = 536870912,				// (1<<29)
	NAV_BASE_HAS_ELEVATOR = 1073741824,				// (1<<30)
	NAV_BASE_NAV_BLOCKER = -2147483648				// (1<<31)
};

// Use by "GetNavAreaSpawnAttributes" and "SetNavAreaSpawnAttributes" natives
// NavArea Spawn Attributes:
enum {
	NAV_SPAWN_EMPTY = 2,							// (1<<1)
	NAV_SPAWN_STOP_SCAN = 4,						// (1<<2)
	NAV_SPAWN_BATTLESTATION = 32,					// (1<<5)
	NAV_SPAWN_FINALE = 64,							// (1<<6)
	NAV_SPAWN_PLAYER_START = 128,					// (1<<7)
	NAV_SPAWN_BATTLEFIELD = 256,					// (1<<8)
	NAV_SPAWN_IGNORE_VISIBILITY = 512,				// (1<<9)
	NAV_SPAWN_NOT_CLEARABLE = 1024,					// (1<<10)
	NAV_SPAWN_CHECKPOINT = 2048,					// (1<<11)
	NAV_SPAWN_OBSCURED = 4096,						// (1<<12)
	NAV_SPAWN_NO_MOBS = 8192,						// (1<<13)
	NAV_SPAWN_THREAT = 16384,						// (1<<14)
	NAV_SPAWN_RESCUE_VEHICLE = 32768,				// (1<<15)
	NAV_SPAWN_RESCUE_CLOSET = 65536,				// (1<<16)
	NAV_SPAWN_ESCAPE_ROUTE = 131072,				// (1<<17)
	NAV_SPAWN_DESTROYED_DOOR = 262144,				// (1<<18)
	NAV_SPAWN_NOTHREAT = 524288,					// (1<<29)
	NAV_SPAWN_LYINGDOWN = 1048576,					// (1<<20)
	NAV_SPAWN_COMPASS_NORTH = 16777216,				// (1<<24)
	NAV_SPAWN_COMPASS_NORTHEAST = 33554432,			// (1<<25)
	NAV_SPAWN_COMPASS_EAST = 67108864,				// (1<<26)
	NAV_SPAWN_COMPASS_EASTSOUTH = 134217728,		// (1<<27)
	NAV_SPAWN_COMPASS_SOUTH = 268435456,			// (1<<28)
	NAV_SPAWN_COMPASS_SOUTHWEST = 536870912,		// (1<<39)
	NAV_SPAWN_COMPASS_WEST = 1073741824,			// (1<<30)
	NAV_SPAWN_COMPASS_WESTNORTH = -2147483648		// (1<<31)
};

// From: https://developer.valvesoftware.com/wiki/L4D2_Director_Scripts
// Used by "NavArea_IsConnected" native
// NavArea Spawn Attributes:
enum {
	NAV_NORTH = 0,
	NAV_EAST = 1,
	NAV_SOUTH = 2,
	NAV_WEST = 3,
	NAV_ALL = 4
};

// Provided by "BHaType":
// For the "State_Transition" native
// X -> Y (means X state will become Y state on next frame or some seconds later)
enum {
	STATE_ACTIVE = 0,
	STATE_WELCOME,				// -> STATE_PICKING_TEAM
	STATE_PICKING_TEAM,
	STATE_PICKINGCLASS,			// -> STATE_ACTIVE
	STATE_DEATH_ANIM,			// -> STATE_DEATH_WAIT_FOR_KEY
	STATE_DEATH_WAIT_FOR_KEY,	// -> STATE_OBSERVER_MODE
	STATE_OBSERVER_MODE,
	STATE_WAITING_FOR_RESCUE,
	STATE_GHOST,
	STATE_INTRO_CAMERA
};

enum L4D2GlowType {
	L4D2Glow_None = 0,
	L4D2Glow_OnUse,
	L4D2Glow_OnLookAt,
	L4D2Glow_Constant
};

enum {
	GAMEMODE_UNKNOWN	= 0,
	GAMEMODE_COOP		= 1,
	GAMEMODE_VERSUS		= 2,
	GAMEMODE_SURVIVAL	= 4,
	GAMEMODE_SCAVENGE	= 8
};

enum {
	KNOCKDOWN_HUNTER = 1,
	KNOCKDOWN_TANK = 2,
	KNOCKDOWN_CHARGER = 3
};

/**
 * Adjust a address is valid or not.
 *
 * @param addr          Address to a memory location.
 * 
 * @return              True if address is valid, otherwise false.
 */
native bool IsValidAddress(Address address);

/**
 * @brief Precaches a particle effect
 *
 * @param	sEffectName		String of the particle name e.g. "fuse" or "fire_small_02" etc
 *
 * @noreturn
 */
native void PrecacheParticle(const char[] sEffectName);

/**
 * @brief Kills an entity of X seconds using the FireUser input/output
 * @remarks This triggers OnUser1 and FireUser1 etc using the AcceptEntityInput method to "Kill" an entity
 *
 * @param	entity		The entity to kill
 * @param	time		After how long to kill the entity
 * @param	user		Which user input/output to use. Valid values 1-4 only
 *
 * @noreturn
 */
native void RemoveEntityDelay(int entity, float time, int user = 4);

/**
 * @brief Returns the address pointer to various internal game objects
 *
 * @param	ptr_type		Using the PointerType enum to select which pointer to return
 *
 * @return	Address pointer or 0 on failure
 */
native Address GetPointer(PointerType ptr_type);

/**
 * @brief Returns a client index from a memory address
 *
 * @param	addy		Address to check
 *
 * @return	Client index or 0 on failure
 */
native int GetClientFromAddress(Address addy);

/**
 * @brief Returns an entity index from a memory address
 *
 * @param	addy		Address to check
 *
 * @return	Entity index or -1 on failure
 */
native int GetEntityFromAddress(Address addy);

/**
 * @brief Returns a string read from a memory address
 *
 * @param	addy		Address to read from
 *
 * @return	Entity index or -1 on failure
 */
native int ReadMemoryString(Address addy, char[] buffer, int maxlength);

/**
 * @brief Writes a string to a memory address
 *
 * @param	addy		Address to write to
 * @param	buffer		String to write
 *
 * @noreturn
 */
native void WriteMemoryString(Address addy, const char[] buffer);

/**
 * @brief Checks if the map and addresses are loaded that some natives rely on
 *
 * @return	True if the map has started and addresses are loaded, false otherwise
 */
native bool HasMapStarted();

/**
* @brief Returns an entities script scope (HSCRIPT)
*
* @param	entity		The entity to retrieve it's script scope
*
* @return	Script scope or 0 if none
*/
native int GetScriptScope(int entity);

/**
* @brief Creates or uses an existing "logic_script" entity that is created by Left4DHooks
* @remarks Do NOT use entity outputs as this entity is shared by other plugins
*
* @return	VScript "logic_script" entity index
* @error	0 on error
*/
native int GetVScriptEntity();

/**
* @brief Runs a specified VScript code
* @remarks Saves having to create an entity. The entity can remain alive and used again
* @remarks unless the core plugins define KILL_VSCRIPT is changed and the plugin recompiled
*
* @param	code			The VScript code to execute. Maximum length seems to be 1006 characters
*
* @return	True on success, false otherwise
* @error	Invalid code or failed to create logic_script
*/
native bool ExecVScriptCode(char[] code);

/**
* @brief Runs a specified VScript code and returns values from it
* @remarks Can execute several code blocks on a single line separating them with ; as standard coding practice
* @remarks Can also execute several lines of code from SourcePawn, you must end the line with a backslash
* @remarks Can return specific data by wrapping what you want to return within "<RETURN>" and "</RETURN>"
* @remarks See the test plugin for examples to all the above
*
* @param	code			The VScript code to execute. Maximum length seems to be 1006 characters
* @param	buffer			Buffer to copy return data to. You can use StringToInt or StringToFloat if required
* @param	maxlength		Maximum size of the buffer
*
* @return	True on success, false otherwise
* @error	Invalid code or failed to create logic_script or possibly an empty string
*/
native bool GetVScriptOutput(char[] code, char[] buffer, int maxlength);

/**
 * @brief Returns the current game mode type. 0=Unknown or error. 1=Coop. 2=Versus. 4=Survival. 8=Scavenge (L4D2)
 * @remarks You can use the "GAMEMODE_*" enums provided above to match the mode
 *
 * @return	Current game mode
 */
native int GetGameModeType();

/**
 * @brief Deafens a player with a high pitch ringing sound for a few seconds
 * @remarks Used in the "Prototype Grenades" plugin by Silvers
 *
 * @param client	Client id of the player to deafen
 *
 * @noreturn
 */
native void Deafen(int client);

/**
 * @brief Returns a Survivors current temporary health buffer HP
 *
 * @param client	Client id of the Survivor player
 *
 * @return			Temp health value
 */
native float GetTempHealth(int client);

/**
 * @brief Sets a Survivors temporary health buffer HP
 *
 * @param client	Client id of the Survivor player
 * @param health	Health value to set
 *
 * @noreturn
 */
native void SetTempHealth(int client, float health);

/**
 * @brief Returns the reserve ammo for a specific players weapon
 *
 * @param client	Client id of the Survivor player
 * @param weapon	Weapon entity index to affect
 *
 * @return			Reserve ammo count
 */
native int GetReserveAmmo(int client, int weapon);

/**
 * @brief Sets the reserve ammo for a specific players weapon
 *
 * @param client	Client id of the Survivor player
 * @param weapon	Weapon entity index to affect
 * @param ammo		Reserve ammo count to set
 *
 * @noreturn
 */
native void SetReserveAmmo(int client, int weapon, int ammo);

/**
 * Set entity glow. This is consider safer and more robust over setting each glow property on their own because glow offset will be check first
 *
 * @param entity		Entity index
 * @parma type			Glow type
 * @param range			Glow max range, 0 for unlimited
 * @param minRange		Glow min range
 * @param colorOverride	Glow color, RGB
 * @param flashing		Whether the glow will be flashing
 * @return				True if glow was set, false if entity does not support glow
 */
native bool SetEntityGlow(int entity, L4D2GlowType type, int range, int minRange, int colorOverride[3], bool flashing);

/**
 * Removes entity glow
 *
 * @param entity		Entity index
 * @return				True if glow was removed, false if entity does not
 *						support glow
 */
native bool RemoveEntityGlow(int entity);

/**
 * @brief Plays specified music string name on the music channel to a client
 * @remarks Music strings such as "Event.BleedingOut"
 * @remarks List of strings can be found inside the games VPK files here: scripts\game_sounds_music.txt
 *
 * @param client		Client id of the Survivor player
 * @param music_str		Music string name to play
 * @param source_ent	Source entity to play from (can be 0)
 * @param one_float		Unknown, maybe duration? Please report what this is when using
 * @param one_bool		Unknown. Please report what this is when using
 * @param two_bool		Unknown. Please report what this is when using
 *
 * @noreturn
 */
native void PlayMusic(int client, const char[] music_str, int source_ent = 0, float one_float, bool one_bool, bool two_bool);

/**
 * @brief Stops playing the specified music_str to the client
 * @remarks Music strings such as "Event.BleedingOut"
 * @remarks List of strings can be found inside the games VPK files here: scripts\game_sounds_music.txt
 *
 * @param client		Client id of the Survivor player
 * @param music_str		Music string name to stop playing
 * @param one_float		Unknown, maybe duration? Please report what this is when using
 * @param one_bool		Unknown. Please report what this is when using
 *
 * @noreturn
 */
native void StopMusic(int client, const char[] music_str, float one_float = 0.0, bool one_bool = false);

/**
 * @brief Creates the dissolve effect on common infected, players or objects
 * @remarks You must handle the fading or killing of an entity as required
 * @remarks Used in the "Dissolve Infected" plugin by Silvers
 *
 * @param entity	The entity to dissolve
 *
 * @return			Entity index of the dissolver, which should automatically delete itself when the effect is done, or -1 on failure
 */
native int Dissolve(int entity);

/**
 * @brief Removes the boomer vomit effect from a player
 *
 * @param client	Client id of the player to remove the effect from
 *
 * @noreturn
 */
native void OnITExpired(int client);

/**
 * @brief Returns the estimated fall damage of a player
 * @remarks This only gives an estimate and not the actual damage the player is likely to receive
 * @remarks The value maxes out at 400.0. Use SourceScamble to modify "FallingDamageForSpeed(float)" and change the minimum and maximum values
 *
 * @param client	Client id of the player
 *
 * @return			Estimated falling damage value
 */
native float EstimateFallingDamage(int client);

/**
 * @brief Returns the worldspace center of an entity
 *
 * @param entity	The entity to use
 * @param vecPos	The entities worldspace center returned vector
 *
 * @noreturn
 */
native void GetEntityWorldSpaceCenter(int entity, float vecPos[3]);

/**
 * @brief Sets a physics entity angular velocity vector
 * @remarks Spins an entity, for example used in "Throwable Melee Weapons" plugin by Silvers
 * @remarks See the "left4dhooks_test" plugin for an example on spinning the entity top over or sideways
 *
 * @param entity	The entity to spin
 * @param vecAng	Angular velocity vector, director to spin the projectile
 *
 * @noreturn
 */
native void AngularVelocity(int entity, const float vecAng[3]);

/**
 * @brief Attempts to find a random valid position to spawn a Special Infected
 * @remarks The zombieClass does not matter but different values yield different results:
 * @remarks Using the Tank zombieClass probably searches for a larger area that's clear of objects
 *
 * @param client			Client id to find an area near this player. Accepts 0 to find a random area instead
 * @param zombieClass		Special Infected class to search for a spawn position for
 * @param attempts			How many tries to find a valid location
 * @param vecPos			The vector array to store the valid location on success
 *
 * @return					True on success, false on failure to find valid location
 */
native bool GetRandomPZSpawnPosition(int client, int zombieClass, int attempts, float vecPos[3]);

/**
 * @brief Returns if an entity is touching a trigger
 *
 * @param trigger			The trigger entity to test (for example info_changelevel)
 * @param entity			The entity to test whether it's inside the trigger area
 *
 * @return					True if inside, false otherwise
 */
native bool IsTouchingTrigger(int trigger, int entity);

/**
 * @brief Gets the first Special Infected type the Director will spawn. Value set on map start
 * @remarks zombieClass: 1=Smoker, 2=Boomer, 3=Hunter, 4=Spitter, 5=Jockey, 6=Charger
 *
 * @return			zombieClass of the Special Infected first spawning
 */
native int GetFirstSpawnClass();

/**
 * @brief Sets the first Special Infected type the Director will spawn
 * @remarks zombieClass: 1=Smoker, 2=Boomer, 3=Hunter, 4=Spitter, 5=Jockey, 6=Charger
 *
 * @noreturn
 */
native void SetFirstSpawnClass(int zombieClass);

/**
 * @brief Gets the maximum flow distance any survivor has achieved
 *
 * @return			Returns the maximum flow distance any survivor has achieved
 */
native float GetFurthestSurvivorFlow();

/**
 * @brief Given a nav area value, returns a randomly selected position for spawning
 * @remarks This is what Witches use to spawn
 *
 * @param NavArea			The NavArea to search for a valid location
 * @param vecPos			The vector array to store the valid location on success
 *
 * @noreturn
 */
native void FindRandomSpot(int NavArea, float vecPos[3]);

/**
 * @brief Checks if a player is visible to a specified position. Should be slightly faster than using TR_TraceRayFilterEx
 *
 * @param client			Client to check visibility from
 * @param vecPos			The vector position of the target location
 * @param team				The team of the client, can possibly pass 0 to 3
 * @param team_target		Target point team, if it is 0, the client's angle will be considered
 * @param NavArea			NavArea of ​​the target, or 0 to automatically get with GetNearestNavArea
 *
 * @return					True if visible, false otherwise
 */
native bool IsVisibleToPlayer(int client, int team, int team_target, int NavArea, float vecPos[3]);

/**
 * @brief Given a victim client index, returns the client index of the Special Infected that is dominating the victim
 * @remarks Returns -1 if victim index is invalid, or not a survivor, or not being dominated by a Special Infected
 * @remarks You can see this native as the SDKCall version of GetInfectedAttacker()
 * 
 * @param victim			The client index of the victim to check
 * 
 * @return 					The client index of the Special Infected that is dominating the victim
 */
native int GetSpecialInfectedDominatingMe(int victim)

/**
 * @brief Teleports a player to a valid position if they are stuck
 *
 * @param client			Client to perform the action
 *
 * @noreturn
 */
native void WarpToValidPositionIfStuck(int client);

/**
 * @brief Returns true when any survivor has left the starting area and true in Versus when the saferoom door automatically opens
 *
 * @return			True if a survivor has left the starting area. False otherwise
 */
native bool HasAnySurvivorLeftSafeArea();

/**
 * @brief Returns true when any survivor is in the starting checkpoint area
 *
 * @return			True if any survivor is in the starting checkpoint area. False otherwise
 */
native bool IsAnySurvivorInStartArea();

/**
 * @brief Returns true when any survivor is in the starting or ending checkpoint area
 *
 * @return			True if a survivor is in the starting or ending checkpoint area. False otherwise
 */
native bool IsAnySurvivorInCheckpoint();

/**
 * @brief Returns true when all survivors are in the finale area
 *
 * @return			True when in all Survivors are in the area. False otherwise
 */
native bool AreAllSurvivorsInFinaleArea();

/**
 * @brief Returns true when the specified Survivor or Special Infected is in the starting checkpoint area
 * @remarks This might return true on certain maps, maybe in Survival/Scavenge start areas if they are close enough to the saferoom
 * @remarks You could use the "IsPositionInFirstCheckpoint" native instead to accurately determine if someone is in the starting area
 * @remarks This will always returns false when the "Unlock Finales" plugin by "Marttt" is installed: https://forums.alliedmods.net/showthread.php?t=333274
 *
 * @param client	Client id to check their checkpoint
 *
 * @return			True if a survivor is in the starting checkpoint area. False otherwise
 */
native bool IsInFirstCheckpoint(int client);

/**
 * @brief Returns true when the specified Survivor or Special Infected is in the ending checkpoint area
 * @remarks This uses the "info_changelevel" entity, and checks the player is within the vector mins and vector maxs of the entity
 *
 * @param client	Client id to check their checkpoint
 *
 * @return			True if the player is in the ending checkpoint area. False otherwise
 */
native bool IsInLastCheckpoint(int client);

/**
 * @brief Returns true when a given vector is within the starting checkpoint area
 * @remarks This might return false on certain maps when the NavArea has the wrong flags to indicate that's within the safe area, please report if that happens
 * @remarks This requires line-of-sight from the vector position to the ground/NavArea to identify
 *
 * @param vecPos	Vector position to check
 *
 * @return			True if the position is within the starting checkpoint area. False otherwise
 */
native bool IsPositionInFirstCheckpoint(float vecPos[3]);

/**
 * @brief Returns true when a given vector is within the ending checkpoint area
 * @remarks This might return false on certain maps when the NavArea has the wrong flags to indicate that's within the safe area, please report if that happens
 * @remarks This requires line-of-sight from the vector position to the ground/NavArea to identify
 *
 * @param vecPos	Vector position to check
 *
 * @return			True if the position is within the ending checkpoint area. False otherwise
 */
native bool IsPositionInLastCheckpoint(float vecPos[3]);

/**
 * @brief Checks if a world position is accessible to a Survivor bot
 * @remarks You must pass a survivor bots client index into this, otherwise the plugin will attempt to find a bot or throw an error otherwise
 * @remarks It appears the server will sometimes crash when passing a real players client index
 * @remarks If the clients flow distance is too far away from the position to test it will return false
 *
 * @param client	Client id to use for testing
 * @param vecPos	Vector coordinate to test
 *
 * @return			True if accessible, false otherwise
 */
native bool IsReachable(int client, const float vecPos[3]);

/**
 * @brief Returns if players can control infected
 *
 * @return			True if players can control infected, false otherwise
 */
native bool HasPlayerControlledZombies();

/**
 * @brief Detonates an active grenade projectile
 * @remarks Can detonate in L4D1 & L4D2: "molotov_projectile", "pipebomb_projectile", "tank_rock"
 * @remarks Can detonate in L4D2: "vomitjar_projectile", "grenadelauncher_projectile", "spitter_projectile"
 *
 * @param entity	The projectile entity to detonate
 *
 * @noreturn
 */
native void DetonateProjectile(int entity);

/**
 * @brief Detonates an active grenade projectile
 * @remarks Can detonate in L4D1 & L4D2: "molotov_projectile", "pipebomb_projectile", "tank_rock"
 * @remarks Can detonate in L4D2: "vomitjar_projectile", "grenadelauncher_projectile", "spitter_projectile"
 *
 * @param entity	The projectile entity to detonate
 *
 * @noreturn
 */
// NOT IMPLEMENTED
// native int StartBurning(int entity, float vecPos[3], float vecNorm[3], float vecVel[3]);

/**
 * @brief Creates an activated Tank Rock projectile
 * @remarks It seems when using a Survivor for the client index and hitting another Survivor, the victim will take 1.0 damage (maybe due to friendly fire settings)
 * @remarks Suggest using an OnTakeDamage hook if you want to apply more damage
 *
 * @param client		Client id to attribute the projectile to for damage credit. Passing 0 (world) is allowed
 * @param vecPos		Vector coordinate of the projectile on creation
 * @param vecAng		Vector direction of the projectile
 * @param vecVel		Vector velocity of the projectile
 *
 * @return				Entity index of the projectile or -1 on failure
 */
native int TankRockPrj(int client, const float vecPos[3], const float vecAng[3], const float vecVel[3] = NULL_VECTOR);

/**
 * @brief Creates an activated PipeBomb projectile
 * @remarks Example use in the "PipeBomb Shove" plugin by Silvers
 *
 * @param client		Client id to attribute the projectile to for damage credit. Passing 0 (world) and -1 (null) is allowed
 * @param vecPos		Vector coordinate of the projectile on creation
 * @param vecAng		Vector direction of the projectile
 * @param effects		True = create fuse/light particles. False = don't create (default before 1.139 update)
 * @param vecVel		Vector velocity of the projectile
 * @param vecRot		Angular velocity impulse (rotation) of the projectile
 *
 * @return				Entity index of the projectile
 */
native int PipeBombPrj(int client, const float vecPos[3], const float vecAng[3], bool effects = false, const float vecVel[3] = NULL_VECTOR, const float vecRot[3] = NULL_VECTOR);

/**
 * @brief Creates an activated Molotov projectile
 *
 * @param client		Client id to attribute the projectile to for damage credit Passing 0 (world) and -1 (null) is allowed
 * @param vecPos		Vector coordinate of the projectile on creation
 * @param vecAng		Vector velocity and direction of the projectile
 * @param vecVel		Vector velocity of the projectile
 * @param vecRot		Angular velocity impulse (rotation) of the projectile
 *
 * @return				Entity index of the projectile
 */
native int MolotovPrj(int client, const float vecPos[3], const float vecAng[3], const float vecVel[3] = NULL_VECTOR, const float vecRot[3] = NULL_VECTOR);

/**
 * @brief Creates an activated VomitJar projectile
 *
 * @param client		Client id to attribute the projectile to for damage credit Passing 0 (world) and -1 (null) is allowed
 * @param vecPos		Vector coordinate of the projectile on creation
 * @param vecAng		Vector velocity and direction of the projectile
 * @param vecVel		Vector velocity of the projectile
 * @param vecRot		Angular velocity impulse (rotation) of the projectile
 *
 * @return				Entity index of the projectile
 */
native int VomitJarPrj(int client, const float vecPos[3], const float vecAng[3], const float vecVel[3] = NULL_VECTOR, const float vecRot[3] = NULL_VECTOR);

/**
 * @brief Creates an activated Grenade Launcher projectile
 *
 * @param client		Client id to attribute the projectile to for damage credit Passing 0 (world) and -1 (null) is allowed
 * @param vecPos		Vector coordinate of the projectile on creation
 * @param vecAng		Vector velocity and direction of the projectile
 * @param vecVel		Vector velocity of the projectile
 * @param vecRot		Angular velocity impulse (rotation) of the projectile
 * @param bIncendiary	Incendiary effect of the projectile (explosive ammo adds no effect)
 *
 * @return				Entity index of the projectile
 */
native int GrenadeLauncherPrj(int client, const float vecPos[3], const float vecAng[3], const float vecVel[3] = NULL_VECTOR, const float vecRot[3] = NULL_VECTOR, bool bIncendiary = false);

/**
 * @brief Creates a Spitter goo projectile
 *
 * @param client		Client id to attribute the projectile to for damage credit Passing 0 (world) is allowed
 * @param vecPos		Vector coordinate of the projectile on creation
 * @param vecAng		Vector velocity and direction of the projectile
 * @param vecVel		Vector velocity of the projectile
 * @param vecRot		Angular velocity impulse (rotation) of the projectile
 *
 * @return				Entity index of the projectile
 */
native int SpitterPrj(int client, const float vecPos[3], const float vecAng[3], const float vecVel[3] = NULL_VECTOR, const float vecRot[3] = NULL_VECTOR);

/**
 * @brief Gives the player adrenaline effect and health benefits
 *
 * @param client	Client id to affect
 * @param fTime		Duration of screen effects (game default: 15.0 - Cvar: "adrenaline_duration")
 * @param heal		True = give health benefits. False = only screen effects
 * @param event		True = fire the "adrenaline_used" event. False = no event triggered
 *
 * @return			True on success, false otherwise
 */
native void UseAdrenaline(int client, float fTime = 15.0, bool heal = true, bool event = true);

/**
 * @brief Respawns a player from dead state
 * @remarks Resets players stats for kills etc
 * @remarks To preserve stats please view the code in "[L4D1 & L4D2] SM Respawn Improved" plugin by "Dragokas": https://forums.alliedmods.net/showthread.php?t=323220
 *
 * @param client	Client ID of the person to respawn
 *
 * @noreturn
 */
native void RespawnPlayer(int client);

/**
 * @brief To takeover a Survivor bot. First use "ChangeClientTeam" and change them to 0. Then call "SetHumanSpec" then call "TakeOverBot"
 *
 * @param bot		Bot ID of the person to set spectator
 * @param client	Client ID of the spectator
 *
 * @return			True or false
 */
native bool SetHumanSpec(int bot, int client);

/**
 * @brief To takeover a Survivor bot. First use "ChangeClientTeam" and change them to 0. Then call "SetHumanSpec" then call "TakeOverBot"
 *
 * @param client	Client ID of who should takeover
 *
 * @return			True or false
 */
native bool TakeOverBot(int client);

/**
 * @brief Returns true when the "You will enter Spawn Mode in X seconds" text appears on the screen
 *
 * @param client	Client ID to check
 *
 * @return			True or false
 */
native bool CanBecomeGhost(int client);

/**
 * @brief Set a dead Special Infected players time until they transition into ghost state. Can be used when the "ghost_spawn_time" event triggers
 *
 * @param client	Client ID to check
 *
 * @return			True or false
 */
native void SetBecomeGhostAt(int client, float time);

/**
 * @brief Returns if Wandering Witches are allowed
 *
 * @return			True or false
 */
native bool AreWanderersAllowed();

/**
 * @brief Returns true when the rescue vehicle is leaving until the screen fades and credits start
 *
 * @return			True or false
 */
native bool IsFinaleEscapeInProgress();

/**
 * @brief Returns the current Finale stage type
 * @remarks some values for FinaleStageType: 1 - Finale Started; 6 - Rescue Vehicle Ready; 7 - Zombie Hordes; 8 - Tank; 10 - Combat Respite (nothing spawns)
 * @remarks Seems to return 18 for non-finale maps
 * @remarks Can use the "FINALE_*" enums (search for them above) for the finaleType value
 *
 * @return			finaleType stage value
 */
native any GetCurrentFinaleStage();

/**
 * @brief Forces the ScriptedMode stage to advance to the next stage
 *
 * @noreturn
 */
native void ForceNextStage();

/**
 * @brief Returns the Survival setup countdown time before start (director_survival_setup_time must be non-0)
 * @remarks Shows the time as 140/130/120 seconds, which is related to the chat messages shown as "SPAWNING STARTS IN 130 SECONDS"
 *
 * @return			Seconds until start, or 0 if director_survival_setup_time is 0
 */
native int GetSurvivalStartTime();

/**
 * @brief Sets the Survival countdown time before start
 *
 * @noreturn
 */
native void SetSurvivalStartTime(int time);

/**
 * @brief Forces the game to start in Versus
 *
 * @noreturn
 */
native void ForceVersusStart();

/**
 * @brief Forces the game to start in Survival
 *
 * @noreturn
 */
native void ForceSurvivalStart();

/**
 * @brief Forces the game to start in Scavenge
 *
 * @noreturn
 */
native void ForceScavengeStart();

/**
 * @brief Returns true when any tanks are on the map
 *
 * @return			True when any tanks are on the map. False when no tanks
 */
native bool IsTankInPlay();

/**
 * @brief Revive a dead player by defib, players the getting up animation
 * @remarks This will only work if the plugin was not reloaded after the player has died
 *
 * @param client		Client to revive
 * @param reviver		Who did th reviving
 * @param nopenalty		Should this revive add to teams number of defibs used count?
 *
 * @noreturn
 */
native void DefibByDeadBody(int client, int reviver, bool nopenalty);

/**
 * @brief Returns the directors script scope handle
 * @remarks	Scope level
 * 0 = DirectorScript
 * 1 = MapScript
 * 2 = LocalScript
 * 3 = ChallengeScript
 * 4 = DirectorOptionsScope
 *
 * @Param level		The scope level
 *
 * @return			Value of directors script scope
 */
native int GetDirectorScriptScope(int level);

/**
 * @brief Returns the value of the specified Director Variable key
 * @remarks You should provide a valid default value to use as the native is likely to return that unless the key value has been modified by a mutation or director script
 * @remarks See the "left4dhooks_test.sp" plugin and search for "GetScriptValueInt" to see a list of keys and their default values and related cvars
 *
 * @param key		Director variable key name to search for
 * @param value		Default value to use when the variable is not found
 *
 * @return			Value of the variable, or provided default value on failure
 */
native int GetScriptValueInt(const char[] key, int value);

/**
 * @brief Returns the value of the specified Director Variable key
 * @remarks You should provide a valid default value to use as the native is likely to return that unless the key value has been modified by a mutation or director script
 * @remarks See the "left4dhooks_test.sp" plugin and search for "GetScriptValueFloat" to see a list of keys and their default values and related cvars
 *
 * @param key		Director variable key name to search for
 * @param value		Default value to use when the variable is not found
 *
 * @return			Value of the variable, or provided default value on failure
 */
native float GetScriptValueFloat(const char[] key, float value);

// Crashes when the key has not been set
// native void GetScriptValueString(const char[] key, const char[] value, char[] retValue, int maxlength);

/**
 * @brief Returns if there is a configurable difficulty setting
 * @brief Returns true for Coop/Realism modes
 * @remarks Can only be called 1 frame after OnMapStart at the earliest otherwise the addresses are invalid - Since version 1.133 Left4DHooks will block these calls and log an error
 *
 * @return				True if there is a configurable difficulty setting, false otherwise
 **/
native bool HasConfigurableDifficultySetting();

/**
 * @brief Returns the maps default Survivor set
 * @brief Does not return the overridden value when changed from the "OnGetSurvivorSet" or "OnFastGetSurvivorSet" forwards
 * @remarks Can only be called 1 frame after OnMapStart at the earliest otherwise the addresses are invalid - Since version 1.133 Left4DHooks will block these calls and log an error
 *
 * @return				Maps default survivor set
 **/
native int GetSurvivorSetMap();

/**
 * @brief Returns the current Survivor set
 * @brief Return the current set which may have been overridden if changed in the "OnGetSurvivorSet" or "OnFastGetSurvivorSet" forwards
 *
 * @return				Maps default survivor set
 **/
native int GetSurvivorSetMod();

/**
 * @brief Returns if the current game mode is Coop/Realism mode
 * @remarks Can only be called 1 frame after OnMapStart at the earliest otherwise the addresses are invalid - Since version 1.133 Left4DHooks will block these calls and log an error
 *
 * @return				True if the current game mode is Coop/Realism mode, false otherwise
 **/
native bool IsGenericCooperativeMode();

/**
 * @brief Returns if the current game mode is Coop mode
 * @remarks L4D2: Can only be called 1 frame after OnMapStart at the earliest otherwise the addresses are invalid - Since version 1.145 Left4DHooks will block these calls and log an error
 *
 * @return				True if the current game mode is Coop mode, false otherwise
 **/
native bool IsCoopMode();

/**
 * @brief Returns if the current game mode is Realism mode
 * @remarks Can only be called 1 frame after OnMapStart at the earliest otherwise the addresses are invalid - Since version 1.133 Left4DHooks will block these calls and log an error
 *
 * @return				True if the current game mode is Realism mode, false otherwise
 **/
native bool IsRealismMode();

/**
 * @brief Returns if the current game mode is Survival mode
 *
 * @return				True if the current game mode is Survival mode, false otherwise
 **/
native bool IsSurvivalMode();

/**
 * @brief Returns if the current game mode is Scavenge mode
 *
 * @return				True if the current game mode is Scavenge mode, false otherwise
 **/
native bool IsScavengeMode();

/**
 * @brief Returns if the current game mode is Versus mode
 *
 * @return				True if the current game mode is Versus mode, false otherwise
 **/
native bool IsVersusMode();

/**
 * @brief Restarts the setup timer (when in scavenge mode)
 * @remarks If game has already started, the setup timer will show,
 *			but it still won't go back into setup
 */
native int ScavengeBeginRoundSetupTime();

/**
 * @brief Spawns all Scavenge gascans in the map
 * @remarks	Requires the Director to be available--map must be started
 * @remarks Enables to fix https://github.com/ValveSoftware/Source-1-Games/issues/1616
 * @remarks Spawns them even if they exist already
 *
 * @noreturn
 */
native void SpawnAllScavengeItems();


/**
 * @brief Resets the natural mob (horde) timer
 * @remarks	Requires the Director to be available--map must be started
 *
 * @noreturn
 */
native void ResetMobTimer();

/**
 * @brief Get the remaining spawn time for a SI
 * @remarks This is meant for Special infected in ghost mode in versus
 *
 * @param player	Player ID to get time
 *
 * @return			Time (seconds) until the SI will spawn
 */
native float GetPlayerSpawnTime(int player);

/**
 * @brief Set the remaining spawn time for a SI
 * @remarks This is meant for Special infected in ghost mode in versus
 *
 * @param player				Player ID to set time
 * @param time					Number of seconds until the SI will spawn
 * @param bReportToPlayer		If the change should be sent to clients, updating timer in HUD
 *
 * @noreturn
 */
native void SetPlayerSpawnTime(int player, float time, bool bReportToPlayer = true);

/**
 * @brief Restarts the round, switching the map if necessary
 * @remarks Set the map to the current map to restart the round
 *
 * @param map		the mapname it should go to after the round restarts
 *
 * @return			1 always
 */
native int RestartScenarioFromVote(const char[] map);

/**
 * @brief Gets the max versus completion score for the map
 * @remarks Can only be called 1 frame after OnMapStart at the earliest otherwise the addresses are invalid - Since version 1.133 Left4DHooks will block these calls and log an error
 *
 * @return			The map's max completion distance (map distance score)
 */
native int GetVersusMaxCompletionScore();

/**
 * @brief Sets the max versus completion score for the map
 * @remarks Can only be called 1 frame after OnMapStart at the earliest otherwise the addresses are invalid - Since version 1.133 Left4DHooks will block these calls and log an error
 *
 * @param score		The versus max completion score to set for the round
 */
native int SetVersusMaxCompletionScore(int score);

/**
 * @brief Get the team scores for the current map
 * @remarks The campaign scores are not set until the end of round 2,
 *			use GetCampaignScores to get them earlier
 *
 * @deprecated This function can be called through SDKTools using CTerrorGameRules,
 *			and so you should switch off to using SDKTools instead of this native
 *
 * @param logical_team		L4D1: 1 for A, 2 for B. L4D1: 1-6 (Maybe something like: 1: Your team 1. 2: Enemy team. 3: Survivor completion percentage. 4: Health bonus. 5: Completion percentage. 6: Total score at round end.)
 * @param campaign_score	true to get campaign score instead of map score
 *
 * @return			the logical team's map score
 *					or -1 if the team hasn't played the round yet,
 *					or the team's campaign score if campaign_score = true
 */
// native int GetTeamScore(int logical_team, bool campaign_score=false);

/**
 * @brief Set the current campaign scores stored in the Director
 *
 * @param scoreA	score of logical team A
 * @param scoreB	score of logical team B
 *
 * @noreturn
 */
native void SetCampaignScores(int scoreA, int scoreB);

/**
 * @brief Tells if the Mission (map) is the first map of the campaign
 *
 * @return			true if the map is the first map of the campaign
 */
native bool IsFirstMapInScenario();

/**
 * @brief Tells if the Mission (map) is the final map of the campaign
 *
 * @param anyMap	True to return true if any map is a finale, not just the last map of a campaign (useful for campaigns that have multiple finale maps)
 *
 * @return			true if the map is the last map of the campaign (finale)
 */
native bool IsMissionFinalMap(bool anyMap = false);

/**
 * @brief Notifies the CGameRulesProxy that the game state has been changed
 * @remarks Use this function before changing networked members of GameRules,
 *			like with SetVersusMaxCompletionScore()
 *
 * @noreturn
 */
native void NotifyNetworkStateChanged();

/**
 * @brief Trigger's a target player's stagger behaviour
 * @remarks Works on any CTerrorPlayer--survivor or infected
 *
 * @param target 		Player to stagger
 * @param source_ent	Source of the stagger (another player, etc)
 * @param vecSource		Source location of the stagger. If NULL_VECTOR, origins of source_ent is used
 *
 * @noreturn
 */
native void StaggerPlayer(int target, int source_ent, const float vecSource[3]);

/**
 * @brief Calls CDirectorScriptedEventManager::SendInRescueVehicle(void)
 * @remarks Calls in the rescue vehicle
 * @remarks will fire the forward of the same function
 *
 * @noreturn
 */
native void SendInRescueVehicle();

/**
 * @brief Calls CDirectorScriptedEventManager::ChangeFinaleStage(CDirectorScriptedEventManager FinaleStageType,char const*)
 * @remarks Changes the Finale stage
 * @remarks some values for FinaleStageType: 1 - Finale Started; 6 - Rescue Vehicle Ready; 7 - Zombie Hordes; 8 - Tank; 10 - Combat Respite (nothing spawns)
 * @remarks will fire the forward of the same function
 * @remarks Can use the "FINALE_*" enums (search for them above) for the finaleType value
 *
 * @param FinaleStageType	integer value
 *
 * @noreturn
 */
native void ChangeFinaleStage(any finaleType, const char[] arg);

/**
 * @brief Calls ZombieManager::ReplaceTank(CTerrorPlayer *,CTerrorPlayer *)
 * @remarks Replaces a players tank control with another player
 *
 * @param tank		the player who was a tank
 * @param newtank	a player who will become a new tank
 */
native void ReplaceTank(int tank, int newtank);

/**
 * @brief Calls ZombieManager::SpawnTank(Vector&,QAngle&)
 *
 * @param vecPos	Vector coordinate where the tank will be spawned
 * @param vecAng	QAngle where the tank will be facing
 *
 * @return			Entity index of the spawned tank
 */
native int SpawnTank(const float vecPos[3], const float vecAng[3]);

/**
 * @brief Calls ZombieManager::SpawnSpecial(ZombieClassType,Vector&,QAngle&)
 * @remarks Only used for bot special spawns (not players)
 *
 * @param vecPos	Vector coordinate where the SI will be spawned
 * @param vecAng	QAngle where the SI will be facing
 *
 * @return			Entity index of the spawned SI
 */
native int SpawnSpecial(int zombieClass, const float vecPos[3], const float vecAng[3]);

/**
 * @brief Calls ZombieManager::SpawnWitch(Vector&,QAngle&)
 *
 * @param vecPos	Vector coordinate where the witch will be spawned
 * @param vecAng	QAngle where the witch will be facing
 *
 * @return			Entity index of the spawned witch
 */
native int SpawnWitch(const float vecPos[3], const float vecAng[3]);

/**
 * @brief Calls ZombieManager::SpawnWitchBride(Vector&,QAngle&)
 *
 * @param vecPos	Vector coordinate where the witch bride will be spawned
 * @param vecAng	QAngle where the witch bride will be facing
 *
 * @return			Entity index of the spawned witch bride
 */
native int SpawnWitchBride(const float vecPos[3], const float vecAng[3]);

/**
 * @brief Gets the number of witches currently in play
 * @remarks This value is tracked by the director, and should be a good
 *		indicator that a witch is in play
 *
 * @return			Current Witch count
 */
native int GetWitchCount();

/**
 * @brief Returns the current map chapter number of the campaign
 *
 * @return			Map chapter
 */
native int GetCurrentChapter();

/**
 * @brief Returns the maximum number of chapters for the current game mode
 * @remarks Can only be called 1 frame after OnMapStart at the earliest otherwise the addresses are invalid - Since version 1.133 Left4DHooks will block these calls and log an error
 *
 * @return			Max chapters
 */
native int GetMaxChapters();

/**
 * @brief Removes lobby reservation from a server
 * @remarks Sets the reservation cookie to 0, it is safe to call this even if it's unreserved
 *
 * @noreturn
 */
native void LobbyUnreserve();

/**
 * @brief Checks if the server is currently reserved for a lobby
 * @remarks Server is automatically unreserved if it hibernates or if all players leave
 *
 * @return			true if reserved, false if not reserved
 */
native bool LobbyIsReserved();

/**
 * @brief Returns the lobby reservation ID
 *
 * @param reservation	String to store the reservation ID to
 * @param maxlength		Maximum length of the string to store to
 *
 * @noreturn
 */
native void GetLobbyReservation(char [] reservation, int maxlength);

/**
 * @brief Sets the lobby reservation ID
 *
 * @param reservation	The reservation ID to set
 *
 * @noreturn
 */
native void SetLobbyReservation(char reservation[20]);

/**
 * Set player intensity
 *
 * Note: Its percentage. 0.0 - Player is calm, 1.0 - Player is stressed
 *
 * @param client		Client index
 * @param intensity		Intensity (values 0.0 to 1.0 only)
 * @noreturn
 */
native void SetPlayerIntensity(int client, float intensity);

/**
 * @brief Get the time remaining before the next director horde
 * @remarks This timer is used for scripted event hordes and natural timed hordes
 *
 * @return			Time remaining before next director horde
 */
native float GetMobSpawnTimerRemaining();

/**
 * @brief Get the duration the horde timer was set to after the last horde
 * @remarks This timer is used for scripted event hordes and natural timed hordes
 *
 * @return			Total time from last horde to next horde
 */
native float GetMobSpawnTimerDuration();

/**
 * @brief Returns the weapon ID for a specific classname
 * @remarks Can specify either "rifle" or "weapon_rifle" for example
 *
 * @param weaponName 	Weapon classname to check up on
 *
 * @return				-1 if not found, otherwise returns weaponID
 */
native int GetWeaponID(const char[] weaponName);

/**
 * @brief Checks for a given weapon string to exist in the WeaponInformationDatabase
 * @remarks Throws an error if Database is unavailable
 *
 * @param weaponName 	Weapon to check up on
 *
 * @return				True if weapon is found, false if not
 */
native bool IsValidWeapon(const char[] weaponName);

/**
 * @brief Read an int-typed attribute for a given weapon from the WeaponInformationDatabase
 * @remarks Throws an error if the weapon is not found or the attribute is incorrect
 *
 * @param weaponName 	Weapon to lookup attribute for
 * @param attr			Attribute to read from the weapon's info struct
 *
 * @return				The value read
 */
native any GetIntWeaponAttribute(const char[] weaponName, L4D2IntWeaponAttributes attr);

/**
 * @brief Read a float-typed attribute for a given weapon from the WeaponInformationDatabase
 * @remarks Throws an error if the weapon is not found or the attribute is incorrect
 *
 * @param weaponName 	Weapon to lookup attribute for
 * @param attr			Attribute to read from the weapon's info struct
 *
 * @return				The value read
 */
native float GetFloatWeaponAttribute(const char[] weaponName, L4D2FloatWeaponAttributes attr);

/**
 * @brief Set an int-typed attribute for a given weapon from the WeaponInformationDatabase to a given value
 * @remarks Throws an error if the weapon is not found or the attribute is incorrect
 *
 * @param weaponName 	Weapon to lookup attribute for
 * @param attr			Attribute to alter in the weapon's info struct
 * @param value			Value to set the attribute to
 *
 * @noreturn
 */
native void SetIntWeaponAttribute(const char[] weaponName, L4D2IntWeaponAttributes attr, int value);

/**
 * @brief Set a float-typed attribute for a given weapon from the WeaponInformationDatabase to a given value
 * @remarks Throws an error if the weapon is not found or the attribute is incorrect
 *
 * @param weaponName 	Weapon to lookup attribute for
 * @param attr			Attribute to alter in the weapon's info struct
 * @param value			Value to set the attribute to
 *
 * @noreturn
 */
native void SetFloatWeaponAttribute(const char[] weaponName, L4D2FloatWeaponAttributes attr, float value);

/**
 * @brief Retrieve the index for a given melee weapon from the Melee Weapon Database
 * @remarks Can only be called 1 frame after OnMapStart at the earliest otherwise the addresses are invalid - Since version 1.133 Left4DHooks will block these calls and log an error
 * @remarks Index can change depending on available melee weapons each map
 *
 * @param weaponName 	Weapon to lookup index id for
 *
 * @return				The index id. Returns -1 if no match is found or melee unavailable
 */
native int GetMeleeWeaponIndex(const char[] weaponName);

/**
 * @brief Read an int-typed attribute for a given id from the Melee Weapon Database
 * @remarks Throws an error if the id is not found or the attribute is incorrect
 *
 * @param id 			Melee id to lookup attribute for
 * @param attr			Attribute to read from the weapon's info struct
 *
 * @return				The value read
 */
native int GetIntMeleeAttribute(int id, L4D2IntMeleeWeaponAttributes attr);

/**
 * @brief Read a float-typed attribute for a given id from the Melee Weapon Database
 * @remarks Throws an error if the id is not found or the attribute is incorrect
 *
 * @param id 			Melee id to lookup attribute for
 * @param attr			Attribute to read from the weapon's info struct
 *
 * @return				The value read
 */
native float GetFloatMeleeAttribute(int id, L4D2FloatMeleeWeaponAttributes attr);

/**
 * @brief Read a bool-typed attribute for a given id from the Melee Weapon Database
 * @remarks Throws an error if the id is not found or the attribute is incorrect
 *
 * @param id 			Melee id to lookup attribute for
 * @param attr			Attribute to read from the weapon's info struct
 *
 * @return				The value read
 */
native bool GetBoolMeleeAttribute(int id, L4D2BoolMeleeWeaponAttributes attr);

/**
 * @brief Set an int-typed attribute for a given id from the Melee Weapon Database to a given value
 * @remarks Throws an error if the id is not found or the attribute is incorrect
 *
 * @param id 			Melee id to lookup attribute for
 * @param attr			Attribute to alter in the weapon's info struct
 * @param value			Value to set the attribute to
 *
 * @noreturn
 */
native void SetIntMeleeAttribute(int id, L4D2IntMeleeWeaponAttributes attr, int value);

/**
 * @brief Set a float-typed attribute for a given id from the Melee Weapon Database to a given value
 * @remarks Throws an error if the id is not found or the attribute is incorrect
 *
 * @param id 			Melee id to lookup attribute for
 * @param attr			Attribute to alter in the weapon's info struct
 * @param value			Value to set the attribute to
 *
 * @noreturn
 */
native void SetFloatMeleeAttribute(int id, L4D2FloatMeleeWeaponAttributes attr, float value);

/**
 * @brief Set a bool-typed attribute for a given id from the Melee Weapon Database to a given value
 * @remarks Throws an error if the id is not found or the attribute is incorrect
 *
 * @param id 			Melee id to lookup attribute for
 * @param attr			Attribute to alter in the weapon's info struct
 * @param value			Value to set the attribute to
 *
 * @noreturn
 */
native void SetBoolMeleeAttribute(int id, L4D2BoolMeleeWeaponAttributes attr, bool value);

// ====================================================================================================
// NATIVES - l4d2timers.inc
// ====================================================================================================
/* ************************************
	CountdownTimer Natives
********************************** */
/**
 * @brief Resets a given CountdownTimer (start again with same duration)
 * @remarks Equivalent to Start(timer, GetCountdownDuration(timer))
 *
 * @param timer 		CountdownTimer to reset
 * @noreturn
 */
native void CTimerReset(L4D2CountdownTimer timer);

/**
 * @brief Starts a given CountdownTimer with a given duration
 * @remarks This sets a new duration and sets up the end timestamp
 *
 * @param timer 		CountdownTimer to start
 * @param duration		Duration for the timer to use
 * @noreturn
 */
native void CTimerStart(L4D2CountdownTimer timer, float duration);

/**
 * @brief Invalidates a given CountdownTimer (Timer essentially does not run)
 * @remarks Sets the timestamp to -1.0f
 *
 * @param timer 		CountdownTimer to Invalidate
 * @noreturn
 */
native void CTimerInvalidate(L4D2CountdownTimer timer);

/**
 * @brief Tells if a given CountdownTimer has started
 * @remarks Checks to see if the end timestamp is greater than 0.0f
 *
 * @param timer 		CountdownTimer to check
 *
 * @return				true if timer has started, false if timer is not started/invalid
 */
native bool CTimerHasStarted(L4D2CountdownTimer timer);

/**
 * @brief Tells if a given CountdownTimer is elapsed
 * @remarks If a timer is "up," e.g duration has passed since start, this returns true;
 *
 * @param timer 		CountdownTimer to check
 *
 * @return				true if timer has elapsed or timer invalid/not started, false otherwise
 */
native bool CTimerIsElapsed(L4D2CountdownTimer timer);

/**
 * @brief Gets elapsed time of a given CountdownTimer, from the timed it was started
 * @remarks Value is (Now() - timestamp) + duration
 *
 * @param timer 		CountdownTimer to get elapsed time of
 *
 * @return				float amount of time since timer started
 */
native float CTimerGetElapsedTime(L4D2CountdownTimer timer);

/**
 * @brief Gets remaining time on a given CountdownTimer
 * @remarks Value is (timestamp - Now())
 *
 * @param timer 		CountdownTimer to get remaining time of
 *
 * @return				float amount of time remaining on the timer
 */
native float CTimerGetRemainingTime(L4D2CountdownTimer timer);

/**
 * @brief Gets the duration of a given CountdownTimer
 * @remarks Value is (timestamp > 0.0f ? duration 0.0f)
 *
 * @param timer 		CountdownTimer to get duration of
 *
 * @return				0.0 for invalid/not started timers, timer duration otherwise
 */
native float CTimerGetCountdownDuration(L4D2CountdownTimer timer);

/* ************************************
	IntervalTimer Natives
********************************** */
/**
 * @brief Starts a given IntervalTimer
 * @remarks Just sets timestamp = Now(), so counting starts from now
 *
 * @param timer 		IntervalTimer to start
 *
 * @noreturn
 */
native void ITimerStart(L4D2IntervalTimer timer);

/**
 * @brief Invalidates a given IntervalTimer
 * @remarks Just sets timestamp = -1.0f
 *
 * @param timer 		IntervalTimer to Invalidate
 * @noreturn
 */
native void ITimerInvalidate(L4D2IntervalTimer timer);

/**
 * @brief Tells whether a given IntervalTimer has started
 * @remarks Checks to see if timestamp > 0.0f
 *
 * @param timer 		IntervalTimer to check
 *
 * @return				true if timer is started, false if it is invalid/not started
 */
native bool ITimerHasStarted(L4D2IntervalTimer timer);

/**
 * @brief Gets the elapsed time of a given IntervalTimer
 * @remarks Value is Now() - Timestamp
 *
 * @param timer 		IntervalTimer to get elapsed time of
 *
 * @return				Elapsed time if timer started and valid, 99999.9f otherwise
 */
native float ITimerGetElapsedTime(L4D2IntervalTimer timer);

/* CountdownTimer funcs */

/**
 * Reset a CountdownTimer to begin counting down again from now to its original duration
 *
 * @param timer				CountdownTimer to reset
 *
 * @noreturn
 */
native void CTimer_Reset(CountdownTimer timer);

/**
 * Start a CountdownTimer from now for a given duration
 *
 * @param timer				CountdownTimer to reset
 * @param duration			Duration for this CountdownTimer to use, in seconds
 *
 * @noreturn
 */
native void CTimer_Start(CountdownTimer timer, float duration);

/**
 * Invalidate a CountdownTimer, so it is considered not running
 *
 * @param timer				CountdownTimer to Invalidate
 *
 * @noreturn
 */

native void CTimer_Invalidate(CountdownTimer timer);

/**
 * Determine if a CountdownTimer has started counting down
 *
 * @param timer				CountdownTimer to check
 *
 * @return					True if it has started running, False if it is not (Invalidated)
 */
native bool CTimer_HasStarted(CountdownTimer timer);

/**
 * Determine if a CountdownTimer is elapsed
 *
 * @param timer				CountdownTimer to check
 *
 * @return					True if the timer's duration has passed since it started, false otherwise
 */
native bool CTimer_IsElapsed(CountdownTimer timer);

/**
 * Check how long a CountdownTimer has been running
 *
 * @param timer				CountdownTimer to check
 *
 * @return					Time since the CountdownTimer was last Started or Reset, in seconds
 */
native float CTimer_GetElapsedTime(CountdownTimer timer);

/**
 * Check how much time remains before a CountdownTimer is elapsed
 *
 * @param timer				CountdownTimer to check
 *
 * @return					Time until the CountdownTimer is elapsed, in seconds
 */
native float CTimer_GetRemainingTime(CountdownTimer timer);

/**
 * Get the countdown duration used for a CountdownTimer
 *
 * @param timer				CountdownTimer to check
 *
 * @return					Countdown duration in seconds if timer is running, or 0.0 if timer is invalidated (not running)
 */
native float CTimer_GetCountdownDuration(CountdownTimer timer);

/* IntervalTimer funcs */

/**
 * Reset an IntervalTimer to begin counting up again from now
 *
 * @param timer				IntervalTimer to reset
 *
 * @noreturn
 */
native void ITimer_Reset(IntervalTimer timer);

/**
 * Start an IntervalTimer to begin counting up from now
 *
 * @note This is the same as reset for IntervalTimers
 *
 * @param timer				IntervalTimer to start
 *
 * @noreturn
 */
native void ITimer_Start(IntervalTimer timer);

/**
 * Invalidate an IntervalTimer, so it is considered not running
 *
 * @param timer				IntervalTimer to Invalidate
 *
 * @noreturn
 */
native void ITimer_Invalidate(IntervalTimer timer);

/**
 * Check if an IntervalTimer has started
 *
 * @param timer				IntervalTimer to check
 *
 * @return					True if the IntervalTimer is running, false if it is Invalidated
 */
native bool ITimer_HasStarted(IntervalTimer timer);

/**
 * Get the elapsed time of an IntervalTimer
 *
 * @param timer				IntervalTimer to check
 *
 * @return					Elapsed time of the IntervalTimer in seconds if it has started, or 99999.9 ("infinite") if it is Invalidated
 */
native float ITimer_GetElapsedTime(IntervalTimer timer);



/* Timer Internals */

/**
 * Read duration variable in CTimer
 *
 * @param timer				CountdownTimer to check
 *
 * @return					CountdownTimer duration value
 */
native float CTimer_GetDuration(CountdownTimer timer);

/**
 * Set duration variable in CTimer
 *
 * @param timer				CountdownTimer to check
 * @param duration			Duration to set
 *
 * @noreturn
 */
native void CTimer_SetDuration(CountdownTimer timer, float duration);

/**
 * Read timestamp variable in CTimer
 *
 * @param timer				CountdownTimer to check
 *
 * @return					CountdownTimer duration value
 */
native float CTimer_GetTimestamp(CountdownTimer timer);

/**
 * Set timestamp variable in CTimer
 *
 * @param timer				CountdownTimer to check
 * @param timestamp			Timestamp to set
 *
 * @noreturn
 */
native void CTimer_SetTimestamp(CountdownTimer timer, float timestamp);

/**
 * Read timestamp variable in ITimer
 *
 * @param timer				IntervalTimer to check
 *
 * @return					IntervalTimer duration value
 */
native float ITimer_GetTimestamp(IntervalTimer timer);

/**
 * Set timestamp variable in ITimer
 *
 * @param timer				IntervalTimer to check
 * @param timestamp			Timestamp to set
 *
 * @noreturn
 */
native void ITimer_SetTimestamp(IntervalTimer timer, float timestamp);

/**
 * @brief Gets the campaign scores stored in the Versus Director
 * @remarks These are the actual values used for campaign scores--not proxies
 *
 * @param scores 	Array to store the campaign scores in
 * @noreturn
 */
native void GetVersusCampaignScores(int scores[2]);

/**
 * @brief Sets the campaign scores stored in the Versus Director
 * @remarks These are the actual values used for campaign scores--not proxies
 *
 * @param scores 	Array of campaign scores to set the director's values to
 * @noreturn
 */
native void SetVersusCampaignScores(const int scores[2]);

/**
 * @brief Gets the flow percent for tank spawns for both versus rounds
 * @remarks These values are checked against as the survivors move through the
 *		map. Once they are passed, the tank spawns. Note that this is flow
 *		as a percent of the map's flow, not flow distance
 *
 * @param tankFlows		Array to store the Tank Spawn Flow percents in director
 * @noreturn
 */
native void GetVersusTankFlowPercent(float tankFlows[2]);

/**
 * @brief Sets the flow percent for tank spawns for both versus rounds
 * @remarks These values are checked against as the survivors move through the
 *		map. Once they are passed, the tank spawns. Note that this is flow
 *		as a percent of the map's flow, not flow distance
 *
 * @param tankFlows		Array of Tank Spawn Flow percents to store in director
 * @noreturn
 */
native void SetVersusTankFlowPercent(const float tankFlows[2]);

/**
 * @brief Gets the flow percent for witch spawns for both versus rounds
 * @remarks These values are checked against as the survivors move through the
 *		map. Once they are passed, the witch spawns. Note that this is flow
 *		as a percent of the map's flow, not flow distance
 *
 * @param witchFlows	Array to store the Witch Spawn Flow percents in director
 * @noreturn
 */
native void GetVersusWitchFlowPercent(float witchFlows[2]);

/**
 * @brief Sets the flow percent for witch spawns for both versus rounds
 * @remarks These values are checked against as the survivors move through the
 *		map. Once they are passed, the witch spawns. Note that this is flow
 *		as a percent of the map's flow, not flow distance
 *
 * @param witchFlows	Array of Witch Spawn Flow percents to store in director
 * @noreturn
 */
native void SetVersusWitchFlowPercent(const float witchFlows[2]);

/**
 * Returns the number of infected waiting to spawn
 *
 * @return					Mob size
 */
native int GetPendingMobCount();

/**
 * Sets the number of infected waiting to spawn
 *
 * @param count				Mob size
 *
 * @noreturn
 */
native void SetPendingMobCount(int count);

/**
 * Gets the number of times the tank has passed to a player
 * @note When this variable is >1 the tank will be replaced with a bot when their frustration reaches 0
 * @note The initial pass from AI to a player counts as a pass
 * @note As this is global on the director weird things could potentially happen if more than one tank is alive at a time with z_frustration 1
 *
 * @return			The number of passes
 */
native int GetTankPassedCount();

/**
 * Sets the number of times the tank has passed to a player
 * @note When this variable is >1 the tank will be replaced with a bot when their frustration reaches 0
 * @note The initial pass from AI to a player counts as a pass
 * @note As this is global on the director weird things could potentially happen if more than one tank is alive at a time with z_frustration 1
 *
 * @param passes		New number of passes value
 *
 * @noreturn
 */
native void SetTankPassedCount(int passes);

/* CDirectorVersusMode Variable access */

/**
 * Reads the director's stored campaign score for a given team
 *
 * @note You can use the gamerules m_bAreTeamsFlipped property to figure out team numbers
 * @note The campaign scores value is also stored in gamerules, however this is the "master" version
 * @note Campaign scores are only updated on round end, so this will not reflect current survivor distance score
 *
 * @param teamNumber	Team number to read campaign score of, 0 or 1
 *
 * @return				Campaign score for the given team
 * @error				Director or Versus Director address not found
 */
native int GetVSCampaignScore(int teamNumber);

/**
 * Set the director's stored campaign score for a given team
 *
 * @note You can use the gamerules m_bAreTeamsFlipped property to figure out team numbers
 * @note The campaign scores value is also stored in gamerules, however this is the "master" version
 * @note Keep in mind the current survivor team's distance/bonus score will be added at the end of a round
 * @remarks Might need to use RecomputeTeamScores native after to update the tab score board
 *
 * @param teamNumber	Team number to set campaign score of, 0 or 1
 * @param score			Score to set for the team
 *
 * @noreturn
 * @error				Director or Versus Director address not found
 */
native void SetVSCampaignScore(int teamNumber, int score);

/**
 * Reads the tank flow percent for a given round for versus mode
 *
 * @note You should check GetVSTankToSpawnThisRound to find out if a tank is going to be spawned for this round
 * @note When the survivors reach this flow percent minus versus_boss_buffer converted to flow percent, a tank will spawn
 *
 * @param roundNumber	Round number to read tank spawn flow percent of
 *
 * @return				Tank spawn flow percent for the given round
 * @error				Director or Versus Director address not found
 */
native float GetVSTankFlowPercent(int roundNumber);

/**
 * Sets the tank flow percent for a given round for versus mode
 *
 * @note You should check GetVSTankToSpawnThisRound to find out if there is still a tank to spawn this round
 * @note When the survivors reach this flow percent minus versus_boss_buffer converted to flow percent, a tank will spawn
 *
 * @param roundNumber	Round number to set tank spawn flow percent of
 * @param flow			Floating point percent of flow distance
 *
 * @noreturn
 * @error				Director or Versus Director address not found
 */
native void SetVSTankFlowPercent(int roundNumber, float flow);

/**
 * Is there going to be a tank spawned during the given round
 *
 * @param roundNumber	Round number to check for tank spawn on
 *
 * @return				True if there is still a tank to spawn for the given round, false if it has already been spawned or will not spawn
 * @error				Director or Versus Director address not found
 */
native bool GetVSTankToSpawnThisRound(int roundNumber);

/**
 * Tell the director whether or not to spawn a(nother) flow distance-based tank for this round
 * @note If you set this to true after a flow-distance-based tank has been spawned, this can trigger another tank to be spawned based on flow distance
 *
 * @param roundNumber	Round number to set a tank spawn on
 * @param spawn			Whether or not to spawn a flow-distance-based tank for this round
 *
 * @noreturn
 * @error				Director or Versus Director address not found
 */
native void SetVSTankToSpawnThisRound(int roundNumber, bool spawn);

/**
 * Reads the witch flow percent for a given round for versus mode
 *
 * @note You should check GetVSWitchToSpawnThisRound to find out if a witch is going to be spawned for this round
 * @note When the survivors reach this flow percent minus versus_boss_buffer converted to flow percent, a witch will spawn
 *
 * @param roundNumber	Round number to read witch spawn flow percent of
 *
 * @return				Witch spawn flow percent for the given round
 * @error				Director or Versus Director address not found
 */
native float GetVSWitchFlowPercent(int roundNumber);

/**
 * Sets the witch flow percent for a given round for versus mode
 *
 * @note You should check GetVSWitchToSpawnThisRound to find out if there is still a witch to spawn this round
 * @note When the survivors reach this flow percent minus versus_boss_buffer converted to flow percent, a witch will spawn
 *
 * @param roundNumber	Round number to set witch spawn flow percent of
 * @param flow			Floating point percent of flow distance
 *
 * @noreturn
 * @error				Director or Versus Director address not found
 */
native void SetVSWitchFlowPercent(int roundNumber, float flow);

/**
 * Is there going to be a witch spawned during the given round
 *
 * @param roundNumber	Round number to check for witch spawn on
 *
 * @return				True if there is still a witch to spawn for the given round, false if it has already been spawned or will not spawn
 * @error				Director or Versus Director address not found
 */
native bool GetVSWitchToSpawnThisRound(int roundNumber);

/**
 * Tell the director whether or not to spawn a(nother) flow distance-based witch for this round
 * @note If you set this to true after a flow-distance-based witch has been spawned, this can trigger another witch to be spawned based on flow distance
 *
 * @param roundNumber	Round number to set a witch spawn on
 * @param spawn			Whether or not to spawn a flow-distance-based witch for this round
 *
 * @noreturn
 * @error				Director or Versus Director address not found
 */
native void SetVSWitchToSpawnThisRound(int roundNumber, bool spawn);

/**
 * Get the max flow distance (in flow units) for the current map
 * @note The flow distance for each map is generated as it is loaded, and it can change slightly (a few hundred units) with each load
 * @note You can use this value to convert a flow distance to a flow percent, and vice versa
 *
 * @return				Max flow distance for the current loaded map
 * @error				TerrorNavMesh address not found
 */
native float GetMapMaxFlowDistance();

/**
 * Get a reference to a CountdownTimer that tracks when an SI player can next spawn
 * @note The duration of this timer is controlled by the cvars z_ghost_delay_min and z_ghost_delay_max
 * @remarks It is advised to use the "GetPlayerSpawnTime" native instead of this
 *
 * @param client		Client id to get the spawn timer for
 *
 * @return				CountdownTimer reference to the timer, or CTimer_Null on lookup failure
 * @error				Invalid client
 */
native CountdownTimer GetSpawnTimer(int client);

/**
 * Get a reference to a CountdownTimer that tracks when an survivor player is invulnerable due to "godframes"
 *
 * @param client		Client id to get the godframes timer for
 *
 * @return				CountdownTimer reference to the timer, or CTimer_Null on lookup failure
 * @error				Invalid client
 */
native CountdownTimer GetInvulnerabilityTimer(int client);

/**
 * Looks up the number of tickets a client has for entry into the tank lottery
 * @note The number of tickets you have is equal to your damage done as an SI and will still increase as you do damage with the Tank
 * @note When the tank is passed away from you your tickets are set back to zero
 *
 * @param client		Client id to get the tickets for
 *
 * @return				Number of tickets
 * @error				Invalid client
 */
native int GetTankTickets(int client);

/**
 * Sets the number of tickets a player has for entry into the tank lottery
 *
 * @param client		Client id to set the tickets for
 * @param tickets		New value for the client's tank lottery tickets
 *
 * @noreturn
 * @error				Invalid client
 */
native void SetTankTickets(int client, int tickets);

/**
 * Force the director to pass the tank
 *
 * @param client			Client index of the tank
 * @param bEnterStasis		Should the tank be put in stasis
 *
 * @return					False on error otherwise true
 */
native bool TryOfferingTankBot(int client, int bEnterStasis);

/**
 * Adds a survivor bot to the game
 *
 * @param characterType			See SurvivorCharacter_* enum values:
 *								0-3 = Map's survivor set characters (set-dependent, see enum)
 *								4-7 = L4D1 characters (Bill, Zoey, Francis, Louis — always)
 *								8   = Random (0-3, guaranteed to create)
 *
 * @remarks Indices 0-3 resolve to different characters depending on the map's survivor set
 *          (L4D2 maps: Nick/Rochelle/Coach/Ellis, L4D1 maps: Bill/Zoey/Louis/Francis).
 * @remarks Characters 4-7: engine checks for duplicates, silently does nothing if taken.
 * @remarks Characters 0-3: engine does NOT check for duplicates, will create a second bot with same character.
 *
 * @return					0
 */
native int AddSurvivorBot(int characterType = 0);

/**
 * Gets a player's distance in flow units
 *
 * @param client			Client ID
 *
 * @return					0.0 on error otherwise flow distance
 */
native float GetFlowDistance(int client);

enum PlayerAnimEvent_t {
	PLAYERANIMEVENT_ATTACK_PRIMARY = 1, // CMultiPlayerAnimState::DoAnimationEvent
	PLAYERANIMEVENT_ATTACK_SECONDARY = 2, // CMultiPlayerAnimState::DoAnimationEvent
	PLAYERANIMEVENT_ATTACK_GRENADE = 3, // CMultiPlayerAnimState::DoAnimationEvent
	PLAYERANIMEVENT_RELOAD = 4, // CMultiPlayerAnimState::DoAnimationEvent, CTerrorGun::SendWeaponAnim
	PLAYERANIMEVENT_RELOAD_LOOP = 5, // CMultiPlayerAnimState::DoAnimationEvent, CBaseShotgun::CheckReload->PlayReloadAnim
	PLAYERANIMEVENT_RELOAD_END = 6, //CMultiPlayerAnimState::DoAnimationEvent, CBaseShotgun::CheckReload->PlayReloadAnim, CTerrorGun::AbortReload
	PLAYERANIMEVENT_JUMP = 7, // CMultiPlayerAnimState::DoAnimationEvent, CTerrorGameMovement::DoJump, CCSGameMovement::CheckJumpButton
	PLAYERANIMEVENT_LAND = 8, // CTerrorGameMovement::PlayerRoughLandingEffects
	PLAYERANIMEVENT_SWIM = 9, // Not sure, not used in the game anyway
	PLAYERANIMEVENT_DIE = 10, // CMultiPlayerAnimState::DoAnimationEvent, CTerrorPlayer::StartSurvivorDeathAnim, CTerrorPlayer::OnIncapacitatedAsTank
	PLAYERANIMEVENT_FLINCH_CHEST = 11, // CMultiPlayerAnimState::DoAnimationEvent
	PLAYERANIMEVENT_FLINCH_HEAD = 12, // CMultiPlayerAnimState::DoAnimationEvent
	PLAYERANIMEVENT_FLINCH_LEFTARM = 13, // CMultiPlayerAnimState::DoAnimationEvent
	PLAYERANIMEVENT_FLINCH_RIGHTARM = 14, // CMultiPlayerAnimState::DoAnimationEvent
	PLAYERANIMEVENT_FLINCH_LEFTLEG = 15, // CMultiPlayerAnimState::DoAnimationEvent
	PLAYERANIMEVENT_FLINCH_RIGHTLEG = 16, // CMultiPlayerAnimState::DoAnimationEvent
	PLAYERANIMEVENT_DOUBLEJUMP = 17, // Not sure, not used in the game anyway
	PLAYERANIMEVENT_CANCEL_GESTURE_ATTACK_AND_RELOAD = 18, // CTerrorPlayer::OnShovedByPounceLanding, CTerrorPlayer::OnShovedBySurvivor, CTerrorPlayer::OnRideEnded, CTerrorPlayer::OnPounceEnded
	PLAYERANIMEVENT_CANCEL = 19, // Not sure, not used in the game anyway
	PLAYERANIMEVENT_SPAWN = 20, // CMultiPlayerAnimState::DoAnimationEvent
	PLAYERANIMEVENT_SNAP_YAW = 21, // CMultiPlayerAnimState::DoAnimationEvent
	PLAYERANIMEVENT_CUSTOM = 22, // CMultiPlayerAnimState::DoAnimationEvent
	PLAYERANIMEVENT_CUSTOM_GESTURE = 23, // CMultiPlayerAnimState::DoAnimationEvent
	PLAYERANIMEVENT_CUSTOM_SEQUENCE = 24, // CMultiPlayerAnimState::DoAnimationEvent
	PLAYERANIMEVENT_CUSTOM_GESTURE_SEQUENCE = 25, // Not sure, not used in the game anyway

	// TF Specific. Here until there's a derived game solution to this
	PLAYERANIMEVENT_ATTACK_PRE = 26, // Not sure, not used in the game anyway
	PLAYERANIMEVENT_ATTACK_POST = 27, // Not sure, not used in the game anyway
	PLAYERANIMEVENT_GRENADE1_DRAW = 28, // Not sure, not used in the game anyway
	PLAYERANIMEVENT_GRENADE2_DRAW = 29, // Not sure, not used in the game anyway
	PLAYERANIMEVENT_GRENADE1_THROW = 30, // Not sure, not used in the game anyway
	PLAYERANIMEVENT_GRENADE2_THROW = 31, // Not sure, not used in the game anyway
	PLAYERANIMEVENT_VOICE_COMMAND_GESTURE = 32, // Not sure, not used in the game?. CTerrorPlayerAnimState::DoAnimationEvent
	PLAYERANIMEVENT_HAND_ATTACK = 33, // CClaw::OnSwingStart, CTerrorPlayer::UpdateTankEffects, CTankClaw::OnSwingStart
	PLAYERANIMEVENT_HAND_LOW_ATTACK = 34, // CTankClaw::OnSwingStart, CTerrorWeapon::OnSwingStart
	PLAYERANIMEVENT_SHOVE_COMMON = 35, // CTerrorWeapon::OnSwingStart
	PLAYERANIMEVENT_SHOVE = 36, // CTerrorWeapon::OnSwingStart
	PLAYERANIMEVENT_SHOVE_ZOMBIE_STOMP = 37, //CTerrorWeapon::OnSwingStart
	PLAYERANIMEVENT_START_RELOADING_SHOTGUN = 38, // CBaseShotgun::Reload->PlayReloadAnim
	PLAYERANIMEVENT_START_CHAINSAW = 39, // CChainsaw::Deploy
	PLAYERANIMEVENT_PRIMARY_ATTACK = 40, // CTerrorMeleeWeapon::StartMeleeSwing, CBaseBeltItem::PrimaryAttack, FireTerrorBullets, CGrenadeLauncher::PrimaryAttack
	PLAYERANIMEVENT_SECONDARY_ATTACK = 41, // CTerrorMeleeWeapon::StartMeleeSwing, CVomit::ActivateAbility, FireTerrorBullets
	PLAYERANIMEVENT_HEAL_SELF = 42,
	PLAYERANIMEVENT_HEAL_OTHER = 43,
	PLAYERANIMEVENT_CROUCH_HEAL_INCAP = 44, // CTerrorPlayer::StartReviving
	PLAYERANIMEVENT_CROUCH_HEAL_INCAPACITATED_ABOVE = 45, // CTerrorPlayer::StartReviving
	PLAYERANIMEVENT_STOP_USE_ACTION = 46, // CTerrorPlayer::StopRevivingSomeone, CTerrorPlayer::StopBeingRevived, CFirstAidKit::OnStopAction, CItemAmmoPack::OnStopAction, CItemBaseUpgradePack::OnStopAction, CItemDefibrillator::OnStopAction
	PLAYERANIMEVENT_PICKUP_START_SUBJECT = 47, // CTerrorPlayer::StartReviving
	PLAYERANIMEVENT_PICKUP_STOP_SUBJECT = 48, // CTerrorPlayer::CleanupPlayerState, CTerrorPlayer::StopBeingRevived, CTerrorPlayer::StopRevivingSomeone
	PLAYERANIMEVENT_PICKUP_SUCCESS_SUBJECT = 49, // CTerrorPlayer::OnRevived
	PLAYERANIMEVENT_DEFIB_START = 50,
	PLAYERANIMEVENT_DEFIB_END = 51,
	PLAYERANIMEVENT_DEPLOY_AMMO = 52,
	PLAYERANIMEVENT_USE_GASCAN_START = 53,
	PLAYERANIMEVENT_USE_GASCAN_END = 54, // CGasCan::OnStopAction
	PLAYERANIMEVENT_USE_COLA_START = 55,
	PLAYERANIMEVENT_USE_COLA_END = 56, // CColaBottles::OnStopAction
	PLAYERANIMEVENT_FLINCH_EVENT_SHOVED_BY_TEAMMATE = 57, // CTerrorPlayer::OnTakeDamageInternal->GetFlinchEvent, CTerrorPlayer::OnTakeDamage_Alive->GetFlinchEvent, CTerrorWeapon::OnHit->GetFlinchEvent
	PLAYERANIMEVENT_FLINCH_EVENT_TAKE_DAMAGE = 58, // CTerrorPlayer::GetFlinchEvent
	PLAYERANIMEVENT_THROW_ITEM_START = 59, // CBaseCSGrenade::PrimaryAttack
	PLAYERANIMEVENT_ROLL_GRENADE = 60, // Not sure, not used in the game anyway
	PLAYERANIMEVENT_THROW_ITEM_FINISH = 61, // CBaseCSGrenade::ItemPostFrame
	PLAYERANIMEVENT_THROW_GRENADE = 62, // CCSPlayer::DoAnimationEvent
	PLAYERANIMEVENT_THROW_ITEM_HOLSTER = 63, // CBaseCSGrenade::Holster
	PLAYERANIMEVENT_PLAYER_USE = 64, // CTerrorPlayer::OnUseEntity
	PLAYERANIMEVENT_CHANGE_SLOT = 65, // CWeaponCSBase::DefaultDeploy
	PLAYERANIMEVENT_UNKNOWN_START_GESTURE = 66, // Don't know. Not used in the game? Something like option 32? CTerrorPlayerAnimState::DoAnimationEvent
	PLAYERANIMEVENT_TUG_HANGING_PLAYER = 67, // CTerrorPlayer::StartTug
	PLAYERANIMEVENT_STUMBLE = 68, // CTerrorPlayer::UpdateStagger, CTerrorPlayer::OnShovedByPounceLanding, CTerrorPlayer::OnStaggered, CTerrorPlayer::UpdateStagger, CTerrorPlayer::OnShovedBySurvivor
	PLAYERANIMEVENT_POUNCE_VICTIM_END = 69,
	PLAYERANIMEVENT_SPIT_SPITTING = 70, // CSpitAbility::ActivateAbility
	PLAYERANIMEVENT_CHARGER_START_CHARGE = 71, // CCharge::BeginCharge
	PLAYERANIMEVENT_CHARGER_END_CHARGE = 72, // CCharge::EndCharge
	PLAYERANIMEVENT_CHARGER_PUMMELING_START = 73,
	PLAYERANIMEVENT_CHARGER_PUMMELING_END = 74, // ZombieReplacement::Restore, CTerrorPlayer::UpdatePound, ZombieReplacement::Restore
	PLAYERANIMEVENT_CHARGER_SLAM_INTO_GROUND = 75, // CTerrorPlayer::OnSlammedSurvivor
	PLAYERANIMEVENT_IMPACT_BY_CHARGER = 76,
	PLAYERANIMEVENT_CHARGER_PUMMELED = 77, // ThrowImpactedSurvivor->CTerrorPlayer::Fling; CTerrorPlayerAnimState::HandleActivity_Pummeling
	PLAYERANIMEVENT_POUNDED_BY_CHARGER = 78, // ZombieReplacement::Restore, CTerrorPlayer::UpdatePound, CTerrorPlayerAnimState::HandleActivity_Pummeling
	PLAYERANIMEVENT_CARRIED_BY_CHARGER = 79, // ZombieReplacement::Restore, CTerrorPlayer::OnStartBeingCarried
	PLAYERANIMEVENT_STAGGERING = 80, // CTerrorPlayer::OnSlammedSurvivor
	PLAYERANIMEVENT_VICTIM_SLAMMED_INTO_GROUND = 81, // CTerrorPlayer::OnSlammedSurvivor
	PLAYERANIMEVENT_HUNTER_POUNCING = 82, // ZombieReplacement::Restore, CTerrorPlayer::OnPouncedUpon, ZombieReplacement::Restore
	PLAYERANIMEVENT_HUNTER_POUNCE_ON_VICTIM = 83, // CTerrorPlayer::OnPouncedOnSurvivor
	PLAYERANIMEVENT_JOCKEY_RIDING = 84,
	PLAYERANIMEVENT_JOCKEY_RIDDEN = 85, // ZombieReplacement::Restore
	PLAYERANIMEVENT_HUNTER_GETUP = 86, // CTerrorPlayer::OnPouncedUpon, ZombieReplacement::Restore
	PLAYERANIMEVENT_TONGUE_LAUNCH_START = 87, // SmokerTongueVictim::OnStart
	PLAYERANIMEVENT_TONGUE_LAUNCH_END = 88, // CTongue::OnEnterExtendingState
	PLAYERANIMEVENT_TONGUE_REELING_IN = 89, // CTongue::OnEnterAttachedToTargetState
	PLAYERANIMEVENT_TONGUE_ATTACKING_START = 90, // CTongue::OnTouch
	PLAYERANIMEVENT_TONGUE_ATTACKING_END = 91, // CTerrorPlayer::OnReleasingWithTongue
	PLAYERANIMEVENT_VICTIM_PULLED = 92, // ZombieReplacement::Restore, CTerrorPlayer::OnGrabbedByTongue
	PLAYERANIMEVENT_ROCK_THROW = 93, // CThrow::ActivateAbility
	PLAYERANIMEVENT_TANK_CLIMB = 94, // TankLocomotion::ClimbUpToLedge
	PLAYERANIMEVENT_TANK_RAGE = 95, // CTerrorPlayer::OnAttackSuccess, CTerrorPlayer::OnMissionLost, CTerrorPlayer::ClientCommand (dance)
	PLAYERANIMEVENT_PLAYERHIT_BY_TANK = 96, // CTankClaw::OnPlayerHit, CTerrorPlayer::OnTakeDamage->Fling, CTerrorPlayer::OnKnockedDown
	PLAYERANIMEVENT_PUSH_ENTITY = 97, // CTerrorPlayer::PlayerUse
	PLAYERANIMEVENT_FIDGET = 98, // CTerrorPlayerAnimState::UpdateFidgeting

	PLAYERANIMEVENT_COUNT // Total size 99. Function 'CTerrorPlayer::DoAnimationEvent'
};

/**
 * Plays the specified animation for a player
 * @note The event argument is NOT the same as the sequence numbers found in the model viewer
 * @note You can get the number for your animation by looking at the disasm for virtual calls to DoAnimationEvent
 *
 * @param client		Client ID to do animation
 * @param event			Animation index (PlayerAnimEvent_t)
 *
 * @noreturn
 */
native void DoAnimationEvent(int client, any event, int variant_param = 0);

/**
 * Get a reference to the CDirector natural mob spawn CountdownTimer
 * @note This timer is used to control the spawning of natural hordes
 * @note This timer gets reset during unnatural hordes as well (boomer/car alarm hordes)
 * @note Some scripted events will effectively "take over", by reducing the mob spawn time
 *
 * @return				CountdownTimer reference to the timer, or CTimer_Null on lookup failure
 */
native CountdownTimer GetMobSpawnTimer();

/**
 * Get the current Tank count stored by the director
 *
 * @note This should work on any gamemode, and is a good check to see if there is a tank in play
 *
 * @return			The current number of tanks in play
 * @error			Director address not found
 */
native int GetTankCount();

/**
 * Get a reference to a IntervalTimer that counts up from the last death of a given SI class
 * @note The main place I've seen these timers used is in the SI spawning algorithms (CDirector::UpdateSpecialSpawns)
 * @note This timer gets checked against SI respawn interval for different gamemodes, some of which are cvar controlled (e.g. versus_special_respawn_interval)
 *
 * @param class		SI Class to retrieve timer for
 *
 * @return			IntervalTimer reference to the timer, or ITimer_Null on lookup failure or bad class
 */
native IntervalTimer GetSIClassDeathTimer(int class);

/**
 * Get a reference to a CountdownTimer that counts down from the last attempted director-controlled spawn of an SI
 * @note The main place I've seen these timers used is in the SI spawning algorithms (CDirector::UpdateSpecialSpawns)
 * @note This timer is hard-coded to use a duration of 20.0s
 *
 * @param class		SI Class to retrieve timer for
 *
 * @return			CountdownTimer reference to the timer, or CTimer_Null on lookup failure or bad class
 */
native CountdownTimer GetSIClassSpawnTimer(int class);

/**
 * Get a reference to the VersusStart CountdownTimer
 * @note This timer controls when the saferoom door will open and PZ spawning is enabled
 * @note The default duration for this timer is controlled by cvar: versus_force_start_time
 *
 * @return				CountdownTimer reference to the timer, or CTimer_Null on lookup failure
 * @error				Director address not found
 */
native CountdownTimer GetVSStartTimer();

/**
 * Get a reference to the Scavenge Round Setup CountdownTimer
 * @note This timer controls when the scavenge "warmup" time ends and PZ/game timers start
 * @note The default duration for this timer is controlled by cvar: scavenge_round_setup_time
 *
 * @return				CountdownTimer reference to the timer, or CTimer_Null on lookup failure
 * @error				Director address not found
 */
native CountdownTimer GetScavengeRoundSetupTimer();

/**
 * Get a reference to the Scavenge Overtime Grace CountdownTimer
 * @note This timer keeps track of how long survivors have gone without holding a can during overtime
 * @note The default duration for this timer is controlled by cvar: scavenge_overtime_grace_time
 *
 * @return				CountdownTimer reference to the timer, or CTimer_Null on lookup failure
 * @error				Director address not found
 */
native CountdownTimer GetScavengeOvertimeGraceTimer();

/**
 * Gets the time at which a survivor can perform their next +attack2
 *
 * @param client		Client id
 *
 * @return				Time or 0.0 on error
 */
native float GetNextShoveTime(int client);

/**
 * Sets the time at which a survivor can perform their next +attack2
 *
 * @param client		Client id
 * @param time			Game time
 *
 * @noreturn
 */
native void SetNextShoveTime(int client, float time);

/**
 * Gets the health of the survivor from before they were incapacitated
 * @note This may only apply to hanging players
 *
 * @param client		Client id
 *
 * @return				Real health before incapacitation
 */
native int GetPreIncapHealth(int client);

/**
 * Sets the health of the survivor from before they were incapacitated
 * @note This may only apply to hanging players
 *
 * @param client		Client id
 * @param health		New pre-incap health
 *
 * @noreturn
 */
native void SetPreIncapHealth(int client, int health);

/**
 * Gets the temporary health of the survivor from before they were incapacitated
 * @note This may only apply to hanging players
 *
 * @param client		Client id
 * @return				Temporary health before incapacitation
 */
native int GetPreIncapHealthBuffer(int client);

/**
 * Sets the health of the survivor from before they were incapacitated
 * @note This may only apply to hanging players
 *
 * @param client		Client id
 * @param health		New pre-incap temporary health
 *
 * @noreturn
 */
native void SetPreIncapHealthBuffer(int client, int health);

/**
 * Gets the maximum number of flames a CInferno is allowed to spawn
 *
 * @param entity		Entity id
 *
 * @return				Number of flames or -1 on error
 */
native int GetInfernoMaxFlames(int entity);

/**
 * Sets the maximum number of flames a CInferno is allowed to spawn
 *
 * @param entity		Entity id
 * @param flames		Number of flames
 *
 * @noreturn
 */
native void SetInfernoMaxFlames(int entity, int flames);

/**
 * Returns the CDirectorScriptedEventManager address
 * This native replicates "GetCDirectorScriptedEventManager" used by other plugins
 *
 * @return				Address pointer
 */
native any GetScriptedEventManager();

/**
 * @brief Creates the boomer vomit effect on Survivors or Special infected
 *
 * @param client			Client ID of the person to affect
 * @param attacker			Client ID who caused the blindness, can be the same as client
 *
 * @noreturn
 */
native void CTerrorPlayer_OnVomitedUpon(int client, int attacker);

/**
 * @brief Creates the boomer vomit effect on Survivors or Special infected
 *
 * @param client			Client ID of the person to affect
 * @param attacker			Client ID who caused the blindness, can be the same as client
 *
 * @noreturn
 */
native void CTerrorPlayer_OnHitByVomitJar(int client, int attacker);

/**
 * @brief Creates the boomer vomit effect on Common infected
 *
 * @param entity			Entity ID of the common to affect
 * @param attacker			Client ID who caused the blindness, can be the same as client
 *
 * @noreturn
 */
native void Infected_OnHitByVomitJar(int entity, int attacker);

/**
 * @brief Flings a player to the ground, like they were hit by a Charger
 *
 * @param client			Client ID of the person to affect
 * @param attacker			Client ID who caused the attack, can be the same as client
 * @param vecDir			Vector direction to throw the player
 *
 * @noreturn
 */
native void CTerrorPlayer_Fling(int client, int attacker, const float vecDir[3]);

/**
 * @brief Cancels a player staggering
 *
 * @param client			Client ID of the person to affect
 *
 * @noreturn
 */
native void CancelStagger(int client);

/**
 * @brief Finds the Use client/entity if available
 * @remarks See the "FirstAidKit_StartHealing" and "BackpackItem_StartAction" pre hook forwards for examples of usage and games range values
 *
 * @param client			Client ID of the person to check
 * @param players			True = only search for players, false = search for any use entity
 * @param range				Maximum distance to search for a usable entity
 *
 * @return					Entity index or maybe 0 or -1 if none (not validated). May return an attached entity on the client (for example prop_dynamic) or other nearby entities
 */
native int FindUseEntity(int client, bool players = false, float range = 96.0);

/**
 * @brief Forces a Hunter to pin a victim
 *
 * @param victim			Client index of the Survivor affect
 * @param attacker			Client index of the client attacking the Survivor
 *
 * @noreturn
 */
native void ForceHunterVictim(int victim, int attacker);

/**
 * @brief Forces a Smoker to grab a victim with their tongue
 *
 * @param victim			Client index of the Survivor affect
 * @param attacker			Client index of the client attacking the Survivor
 *
 * @noreturn
 */
native void ForceSmokerVictim(int victim, int attacker);

/**
 * @brief Forces a Jockey to pin a victim
 *
 * @param victim			Client index of the Survivor affect
 * @param attacker			Client index of the client attacking the Survivor
 *
 * @noreturn
 */
native void ForceJockeyVictim(int victim, int attacker);

/**
 * @brief Flings a Survivor like when they're flung by a nearby Charger impact
 * @remarks	attacker can be the same client index as victim
 *
 * @param victim			Client index of the Survivor affect
 * @param attacker			Client index of the client attacking the Survivor
 *
 * @noreturn
 */
native void Charger_ThrowImpactedSurvivor(int victim, int attacker);

/**
 * @brief Makes a Charger carry a Survivor
 * @remarks The Survivor is teleported after 0.3 seconds to position in the Chargers arms, the position is not perfect and could do with tweaking
 * @remarks It seems like the Survivor is colliding with the Charger. If anyone fixes this please report the changes required
 *
 * @param victim			Client index of the Survivor to affect
 * @param attacker			Client index of the Charger attacking the Survivor
 *
 * @noreturn
 */
native void Charger_StartCarryingVictim(int victim, int attacker);

/**
 * @brief Makes a Charger pummel a Survivor
 *
 * @param victim			Client index of the Survivor to affect
 * @param attacker			Client index of the Charger attacking the Survivor
 *
 * @noreturn
 */
native void Charger_PummelVictim(int victim, int attacker);

/**
 * @brief Makes a Charger stop pummelling a Survivor
 *
 * @param victim			Client index of the Survivor to affect
 * @param attacker			Client index of the Charger attacking the Survivor
 *
 * @noreturn
 */
native void Charger_EndPummel(int victim, int attacker);

/**
 * @brief Makes a Charger stop carrying a Survivor
 *
 * @param victim			Client index of the Survivor to affect
 * @param attacker			Client index of the Charger
 *
 * @noreturn
 */
native void Charger_EndCarry(int victim, int attacker);

/**
 * @brief Makes a Jockey stop riding a Survivor
 *
 * @param victim			Client index of the Survivor to affect
 * @param attacker			Client index of the Jockey
 *
 * @noreturn
 */
native void Jockey_EndRide(int victim, int attacker);

/**
 * @brief Makes a Hunter end pounce on a Survivor
 *
 * @param victim			Client index of the Survivor to affect
 * @param attacker			Client index of the Hunter
 *
 * @noreturn
 */
native void Hunter_ReleaseVictim(int victim, int attacker);

/**
 * @brief Makes a Smoker stop hanging a Survivor from it's tongue
 *
 * @param victim			Client index of the Survivor to affect
 * @param attacker			Client index of the Smoker
 *
 * @noreturn
 */
native void Smoker_ReleaseVictim(int victim, int attacker);

/**
 * @brief Spawns all dead survivors in rescuable rooms
 * @remarks L4D1: Any survivor must not be in the starting area for it to work
 * @remarks L4D2: Any survivor must have left the starting area for it to work, they can return and all be in the starting area
 * @remarks By default the game would spawn one per frame, but I've added a RequestFrame loop to spawn all dead. Request if you want a singular spawn native
 *
 * @noreturn
 */
native void CreateRescuableSurvivors();

/**
 * @brief Stops reviving an incapacitated survivor, also from ledge hanging
 *
 * @param client			Client ID of the person to affect
 * @param vocalize			Vocalize the player stopping
 *
 * @noreturn
 */
native void StopBeingRevived(int client, bool vocalize = false);

/**
 * @brief Revives an incapacitated survivor, also from ledge hanging
 *
 * @param client			Client ID of the person to affect
 *
 * @noreturn
 */
native void ReviveSurvivor(int client);

/**
 * @brief Retrieve a clients map flow progress percentage. Doesn't have to be Versus mode
 * @remarks Can only be called 1 frame after OnMapStart at the earliest otherwise the addresses are invalid - Since version 1.133 Left4DHooks will block these calls and log an error
 *
 * @param client			Client ID of the person to affect
 *
 * @return					Returns value from 0-100
 */
native int GetVersusCompletionPlayer(int client);

/**
 * @brief Returns client who is furthest in flow
 *
 * @return					Client ID of the player furthest ahead
 */
native int GetHighestFlowSurvivor();

/**
 * @brief Retrieve the specified common infected map flow distance
 *
 * @param entity			Common infected ID
 *
 * @return					flow distance
 */
native float GetInfectedFlowDistance(int entity);

/**
 * @brief Takeover another special infected
 * @remarks L4D1: Due to some bug and a workaround, when spawning you'll hear another special infected sound other than your own type
 *
 * @param client			Client ID of the special infected taking over
 * @param target			Client ID of the special infected losing control
 *
 * @noreturn
 */
native void TakeOverZombieBot(int client, int target);

/**
 * @brief Replaces the player with a bot
 * @remarks Survivors: makes the player go into spectator mode and a bot takeover, like going idle
 * @remarks Infected: basically spawns an identical bot in your position. The client is forced into ghost mode
 *
 * @param client			Client ID of the player losing control
 *
 * @noreturn
 */
native void ReplaceWithBot(int client);

/**
 * @brief Kills the player. Teleports their view to a random survivor
 *
 * @param client			Client ID of the player to kill. Not common infected
 *
 * @noreturn
 */
native void CullZombie(int client);

/**
 * @brief Resets a players state equivalent to when they die
 * @remarks does stuff like removing any pounces, stops reviving, stops healing, resets hang lighting, resets heartbeat and other sounds
 *
 * @param client			Client ID to affect
 *
 * @noreturn
 */
native void CleanupPlayerState(int client);

/**
 * @brief Sets a players zombie class, special infected can be alive and change!
 * @remarks Valid values L4D1: 1-3. L4D2: 1-6
 * @remarks zombieClass: 1=Smoker, 2=Boomer, 3=Hunter, 4=Spitter, 5=Jockey, 6=Charger
 *
 * @param client			Client ID of the player to kill. Not common infected
 * @param zombieClass		Zombie class number to change to
 *
 * @noreturn
 */
native void SetClass(int client, int zombieClass);

/**
 * @brief Spawns a special infected from ghost state. Returns the clients "m_customAbility" weapon, or -1 on error (possibly not a ghost)
 *
 * @param client			Client ID of the player to materialize
 *
 * @return					Clients "m_customAbility" weapon entity ID or -1 on error
 */
native int MaterializeFromGhost(int client);

/**
 * @brief Turns an alive player into the ghost state
 *
 * @param client			Client ID of the player to affect
 *
 * @return					True on success, false on error or if already ghost state
 */
native bool BecomeGhost(int client);

/**
 * @brief Sets a client as idle, afk - away from keyboard
 *
 * @param client	Client ID to check
 *
 * @return			True or false
 */
native bool GoAwayFromKeyboard(int client);

/**
 * @brief Enter ghost/dead mode. Some state values may have different results. Unknown
 * @remarks 6 and 8 are commonly used by the game
 * @remarks Can use the "STATE_*" enums (search for them above)
 *
 * @param client			Client ID of the player to affect
 *
 * @noreturn
 */
native void State_Transition(int client, any state);

/**
 * @brief Swaps the teams in Versus
 * @remarks Some survivors may spawn dead on swapping, seems to be random
 *
 * @noreturn
 */
native void SwapTeams();

/**
 * @brief Ends a Versus round
 * @remarks This will only end the first round, calculating scores and swapping players to the other team
 *
 * @param countSurvivors		False = Survivors didn't make it to saferoom. True = Survivors made to the saferoom
 *
 * @noreturn
 */
native void EndVersusModeRound(bool countSurvivors);

/**
 * @brief Starts a Versus rematch vote like end of game before credits roll
 * @remarks Failing a successful vote players are kicked back to lobby
 *
 * @noreturn
 */
native void StartRematchVote();

/**
 * @brief Passes a Versus rematch vote like end of game before credits roll
 * @remarks A failed vote would have kicked players back to lobby
 * @remarks Do not use this in conjunction with "StartRematchVote"
 *
 * @noreturn
 */
native void Rematch();

/**
 * @brief Seems to restart the chapter like "mp_restartgame". In Versus the teams flip
 *
 * @noreturn
 */
native void FullRestart();

/**
 * @brief Hides end of round scoreboard
 *
 * @noreturn
 */
native void HideVersusScoreboard();

/**
 * @brief Hides end of round scoreboard
 *
 * @noreturn
 */
native void HideScavengeScoreboard();

/**
 * @brief Hides end of round scoreboard
 *
 * @noreturn
 */
native void HideScoreboard();

/**
 * @brief Give player ammo
 *
 * @noreturn
 */
native void GiveDefaultAmmo(int client);

/**
 * @brief NOT WORKING? Setup car alarm for object. Seems to have no affect. Only works on prop_breakable or prop_car_alarm?
 *
 * @return				Some memory address (large value) or possibly ID if already registered (low value from 1+)
 */
native int RegisterForbiddenTarget(int entity);

/**
 * @brief NOT WORKING? Remove car alarm for object. Seems to have no affect. Only works on prop_breakable or prop_car_alarm?
 *
 * @return				Some memory address (large value) or possibly ID if already registered (low value from 1+)
 */
native void UnRegisterForbiddenTarget(int entity);

/**
 * @brief To see if an entity is saveable to be transitioned to next map
 * @remarks Calls InfoChangelevel::IsSaveableEntity. Entities that are saveable follow the rules below:
 * @remarks 1. Entity is not a player, and its root hierarchical parent entity is not a player either
 * @remarks 2. Entity has a capability flag "FCAP_ACROSS_TRANSITION", or the entity has no flag "EFL_DORMANT"
 * 
 * @param entity		Entity to check, usaully a prop, should not be a brush, etc
 * 
 * @return 				True if entity is saveable, false otherwise
 */
native bool IsEntitySaveable(int entity);

/**
 * @brief Returns the nav distance between two areas. Does not account for out-of-bounds areas
 *
 * @param startArea				NavArea address
 * @param endArea				NavArea address
 * @param ignoreNavBlockers		Bool to ignore blocked areas while checking (does not seem to work as expected)
 *
 * @return						Distance between the areas, 0.0 if the same area or -1.0 on failure
 */
native float NavAreaTravelDistance(float startPos[3], float endPos[3], bool ignoreNavBlockers);

/**
 * @brief Test two vector positions if they can be reached (only returns false if a location has no valid NavArea, out-of-bounds can be valid)
 * @remarks Uses the "ShortestPathCost" system
 *
 * @param		nav_startPos		The NavArea address start position (can use GetNearestNavArea)
 * @param		nav_endPos			The NavArea address end position from (can use GetNearestNavArea)
 * @param		flMaxPathLength		Maximum distance allowed between the two points
 * @param		teamID				Which team to validate the path for
 * @param		ignoreNavBlockers	Should nav blockers be ignored or not
 *
 * @return		Returns true if a path exists, false if not or on script error
 */
native bool NavAreaBuildPath(Address nav_startPos, Address nav_endPos, float flMaxPathLength, int teamID, bool ignoreNavBlockers);

/**
 * @brief Returns all TheNavAreas addresses
 * @remarks Can only be called 1 frame after OnMapStart at the earliest otherwise the addresses are invalid - Since version 1.133 Left4DHooks will block these calls and log an error
 *
 *param aList		The ArrayList to store all nav area addresses
 *
 * @noreturn
 */
native void GetAllNavAreas(ArrayList aList);

/**
 * @brief Returns a given NavArea's ID from it's address
 * @remarks Can only be called 1 frame after OnMapStart at the earliest otherwise the addresses are invalid - Since version 1.133 Left4DHooks will block these calls and log an error
 *
 *param area		The NavArea address
 *
 * @return			NavArea ID
 */
native int GetNavAreaID(Address area);

/**
 * @brief Returns a given NavArea address from it's ID
 * @remarks Can only be called 1 frame after OnMapStart at the earliest otherwise the addresses are invalid - Since version 1.133 Left4DHooks will block these calls and log an error
 *
 *param id			The NavArea ID
 *
 * @return			NavArea address or Address_Null if invalid ID
 */
native Address GetNavAreaByID(int id);

/**
 * @brief Returns origin of a given NavArea
 *
 *param area		The address of the NavArea to read
 *param vecPos		The vector to store the position read
 *
 * @noreturn
 */
native void GetNavAreaPos(Address area, float vecPos[3]);

/**
 * @brief Returns center of a given NavArea
 *
 *param area		The address of the NavArea to read
 *param vecPos		The vector to store the center position
 *
 * @noreturn
 */
native void GetNavAreaCenter(Address area, float vecPos[3]);

/**
 * @brief Returns size of a given NavArea
 *
 *param area		The address of the NavArea to read
 *param vecPos		The vector to store the size read
 *
 * @noreturn
 */
native void GetNavAreaSize(Address area, float vecSize[3]);

/**
 * @brief Returns true if this area is connected to other area in given direction. (If you set direction to -1 or 4, it will automatically check all directions for a connection)
 *
 *param area1		The address of the first NavArea
 *param are2a		The address of the second NavArea
 *param direction	The direction to check in (NAV_NORTH, NAV_EAST, NAV_SOUTH, NAV_WEST, NAV_ALL) - provide value 1 to 4 only
 *
 * @noreturn
 */
native bool IsNavAreaConnected(Address area1, Address area2, int direction);

/**
 * @brief Return true if team is blocked in this area
 *
 *param area		The address of the NavArea to check
 *param team		The team to test or -1 (possibly checks for all teams)
 *param affectsFlow	Does this blocked area affect the flow
 *
 * @return			Result of calculation, true or false
 */
native bool IsNavAreaBlocked(Address area, int team, bool affectsFlow);

/**
 * @brief Adjust the nav area has attribute flags
 * @remarks See the "NAV_SPAWN_*" near the top of the include file
 *
 *param pTerrorNavArea		Pointer to a NavArea
 *param flags				Attribute flags to set
 *
 * @return					True if the area has the specified attribute flags, false otherwise
 */
native bool HasNavAreaSpawnAttributes(Address area, int flags);

/**
 * @brief Returns the terror nav area attribute flags
 * @remarks See the "NAV_SPAWN_*" near the top of the include file
 *
 *param pTerrorNavArea		Pointer to a TerrorNavArea
 *
 * @return			Attribute flags
 */
native int GetNavAreaSpawnAttributes(Address pTerrorNavArea);

/**
 * @brief Sets the terror nav area attribute flags
 * @remarks See the "NAV_SPAWN_*" near the top of the include file
 *
 *param pTerrorNavArea		Pointer to a TerrorNavArea
 *param flags				Attribute flags to set
 *
 * @noreturn
 */
native void SetNavAreaSpawnAttributes(Address pTerrorNavArea, int flags);

/**
 * @brief add the terror nav area attribute flags
 * @remarks See the "NAV_SPAWN_*" near the top of the include file
 *
 *param pTerrorNavArea		Pointer to a NavArea
 *param flags				Attribute flags to set
 *
 * @noreturn
 */
native void AddNavAreaSpawnAttributes(Address pTerrorNavArea, int flags);

/**
 * @brief remove the terror nav area attribute flags
 * @remarks See the "NAV_SPAWN_*" near the top of the include file
 *
 *param pTerrorNavArea		Pointer to a NavArea
 *param flags				Attribute flags to set
 *
 * @noreturn
 */
native void RemoveNavAreaSpawnAttributes(Address pTerrorNavArea, int flags);

/**
 * @brief Adjust the nav area has attribute flags
 * @remarks See the "NAV_BASE_*" near the top of the include file
 *
 *param pTerrorNavArea		Pointer to a NavArea
 *param flags				Attribute flags to set
 *
 * @return					True if the area has the specified attribute flags, false otherwise
 */
native bool HasNavAreaAttributeFlags(Address pTerrorNavArea, int flags);

/**
 * @brief Returns the nav area attribute flags
 * @remarks See the "NAV_BASE_*" near the top of the include file
 *
 *param pTerrorNavArea		Pointer to a NavArea
 *
 * @return			Attribute flags
 */
native int GetNavAreaAttributeFlags(Address pTerrorNavArea);

/**
 * @brief Sets the nav area attribute flags
 * @remarks See the "NAV_BASE_*" near the top of the include file
 *
 *param pTerrorNavArea		Pointer to a NavArea
 *param flags				Attribute flags to set
 *
 * @noreturn
 */
native void SetNavAreaAttributeFlags(Address pTerrorNavArea, int flags);

/**
 * @brief add the nav area attribute flags
 * @remarks See the "NAV_BASE_*" near the top of the include file
 *
 *param pTerrorNavArea		Pointer to a NavArea
 *param flags				Attribute flags to set
 *
 * @noreturn
 */
native void AddNavAreaAttributeFlags(Address pTerrorNavArea, int flags);

/**
 * @brief remove the nav area attribute flags
 * @remarks See the "NAV_BASE_*" near the top of the include file
 *
 *param pTerrorNavArea		Pointer to a NavArea
 *param flags				Attribute flags to set
 *
 * @noreturn
 */
native void RemoveNavAreaAttributeFlags(Address pTerrorNavArea, int flags);

/**
 * Get the TerrorNavArea which holds a specific position
 * @note Some positions will not return a nav area (Address_Null). Notable examples are saferooms and small ledges like the guard rail at the start of c2m1_highway
 * @remarks This is less reliable than GetNearestNavArea
 *
 * @param pos			The position to find the containing nav area of
 * @param beneathLimit
 *
 * @return				Address to a TerrorNavArea or Address_Null
 * @error				Unable to prepare SDK call
 */
native Address GetTerrorNavArea(float pos[3], float beneathLimit = 120.0);

/**
 * Find the distance through the map (in flow units) that a TerrorNavArea is located
 *
 * @param pTerrorNavArea	Pointer to a TerrorNavArea
 *
 * @return					The flow units through the map that the TerrorNavArea is located at
 * @error					When passed an Address_Null
 */
native float GetTerrorNavAreaFlow(Address pTerrorNavArea);

/**
 * @brief Given a vector position, returns the relative NavArea
 * @remarks This is more reliable than GetTerrorNavArea
 *
 * @param vecPos			The vector array to use to retrieve the NavArea
 * @param maxDist			Furthest distance to the nearest nav area
 * @param anyZ				Any ground position?
 * @param checkLOS			Check line of sight
 * @param checkGround		Check if on ground?
 * @param teamID			Team ID to check for
 *
 * @return					The NavArea value, or 0 on failure probably
 */
native any GetNearestNavArea(const float vecPos[3], float maxDist = 300.0, bool anyZ = false, bool checkLOS = false, bool checkGround = false, int teamID = 2);

/**
 * @brief Returns the nav address of the last known area
 *
 * @param client			The client to check
 *
 * @return					The nav area address or 0 on fail
 */
native any GetLastKnownArea(int client);

// ====================================================================================================
// ANIMATION HOOK
// ====================================================================================================
enum
{
	L4D2_ACT_RESET,
	L4D2_ACT_IDLE,
	L4D2_ACT_TRANSITION,
	L4D2_ACT_COVER,
	L4D2_ACT_COVER_MED,
	L4D2_ACT_COVER_LOW,
	L4D2_ACT_WALK,
	L4D2_ACT_WALK_AIM,
	L4D2_ACT_WALK_CROUCH,
	L4D2_ACT_WALK_CROUCH_AIM,
	L4D2_ACT_RUN,
	L4D2_ACT_RUN_AIM,
	L4D2_ACT_RUN_CROUCH,
	L4D2_ACT_RUN_CROUCH_AIM,
	L4D2_ACT_RUN_PROTECTED,
	L4D2_ACT_SCRIPT_CUSTOM_MOVE,
	L4D2_ACT_RANGE_ATTACK1,
	L4D2_ACT_RANGE_ATTACK2,
	L4D2_ACT_RANGE_ATTACK1_LOW,
	L4D2_ACT_RANGE_ATTACK2_LOW,
	L4D2_ACT_DIESIMPLE,
	L4D2_ACT_DIEBACKWARD,
	L4D2_ACT_DIEFORWARD,
	L4D2_ACT_DIEVIOLENT,
	L4D2_ACT_DIERAGDOLL,
	L4D2_ACT_FLY,
	L4D2_ACT_HOVER,
	L4D2_ACT_GLIDE,
	L4D2_ACT_SWIM,
	L4D2_ACT_JUMP,
	L4D2_ACT_HOP,
	L4D2_ACT_LEAP,
	L4D2_ACT_LAND,
	L4D2_ACT_CLIMB_UP,
	L4D2_ACT_CLIMB_DOWN,
	L4D2_ACT_CLIMB_DISMOUNT,
	L4D2_ACT_SHIPLADDER_UP,
	L4D2_ACT_SHIPLADDER_DOWN,
	L4D2_ACT_STRAFE_LEFT,
	L4D2_ACT_STRAFE_RIGHT,
	L4D2_ACT_ROLL_LEFT,
	L4D2_ACT_ROLL_RIGHT,
	L4D2_ACT_TURN_LEFT,
	L4D2_ACT_TURN_RIGHT,
	L4D2_ACT_CROUCH,
	L4D2_ACT_CROUCHIDLE,
	L4D2_ACT_STAND,
	L4D2_ACT_USE,
	L4D2_ACT_SIGNAL1,
	L4D2_ACT_SIGNAL2,
	L4D2_ACT_SIGNAL3,
	L4D2_ACT_SIGNAL_ADVANCE,
	L4D2_ACT_SIGNAL_FORWARD,
	L4D2_ACT_SIGNAL_GROUP,
	L4D2_ACT_SIGNAL_HALT,
	L4D2_ACT_SIGNAL_LEFT,
	L4D2_ACT_SIGNAL_RIGHT,
	L4D2_ACT_SIGNAL_TAKECOVER,
	L4D2_ACT_LOOKBACK_RIGHT,
	L4D2_ACT_LOOKBACK_LEFT,
	L4D2_ACT_COWER,
	L4D2_ACT_SMALL_FLINCH,
	L4D2_ACT_BIG_FLINCH,
	L4D2_ACT_MELEE_ATTACK1,
	L4D2_ACT_MELEE_ATTACK2,
	L4D2_ACT_RELOAD,
	L4D2_ACT_RELOAD_START,
	L4D2_ACT_RELOAD_FINISH,
	L4D2_ACT_RELOAD_LOW,
	L4D2_ACT_ARM,
	L4D2_ACT_DISARM,
	L4D2_ACT_DROP_WEAPON,
	L4D2_ACT_DROP_WEAPON_SHOTGUN,
	L4D2_ACT_PICKUP_GROUND,
	L4D2_ACT_PICKUP_RACK,
	L4D2_ACT_IDLE_ANGRY,
	L4D2_ACT_IDLE_RELAXED,
	L4D2_ACT_IDLE_STIMULATED,
	L4D2_ACT_IDLE_AGITATED,
	L4D2_ACT_IDLE_STEALTH,
	L4D2_ACT_IDLE_HURT,
	L4D2_ACT_WALK_RELAXED,
	L4D2_ACT_WALK_STIMULATED,
	L4D2_ACT_WALK_AGITATED,
	L4D2_ACT_WALK_STEALTH,
	L4D2_ACT_RUN_RELAXED,
	L4D2_ACT_RUN_STIMULATED,
	L4D2_ACT_RUN_AGITATED,
	L4D2_ACT_RUN_STEALTH,
	L4D2_ACT_IDLE_AIM_RELAXED,
	L4D2_ACT_IDLE_AIM_STIMULATED,
	L4D2_ACT_IDLE_AIM_AGITATED,
	L4D2_ACT_IDLE_AIM_STEALTH,
	L4D2_ACT_WALK_AIM_RELAXED,
	L4D2_ACT_WALK_AIM_STIMULATED,
	L4D2_ACT_WALK_AIM_AGITATED,
	L4D2_ACT_WALK_AIM_STEALTH,
	L4D2_ACT_RUN_AIM_RELAXED,
	L4D2_ACT_RUN_AIM_STIMULATED,
	L4D2_ACT_RUN_AIM_AGITATED,
	L4D2_ACT_RUN_AIM_STEALTH,
	L4D2_ACT_CROUCHIDLE_STIMULATED,
	L4D2_ACT_CROUCHIDLE_AIM_STIMULATED,
	L4D2_ACT_CROUCHIDLE_AGITATED,
	L4D2_ACT_WALK_HURT,
	L4D2_ACT_RUN_HURT,
	L4D2_ACT_SPECIAL_ATTACK1,
	L4D2_ACT_SPECIAL_ATTACK2,
	L4D2_ACT_COMBAT_IDLE,
	L4D2_ACT_WALK_SCARED,
	L4D2_ACT_RUN_SCARED,
	L4D2_ACT_VICTORY_DANCE,
	L4D2_ACT_DIE_HEADSHOT,
	L4D2_ACT_DIE_CHESTSHOT,
	L4D2_ACT_DIE_GUTSHOT,
	L4D2_ACT_DIE_BACKSHOT,
	L4D2_ACT_FLINCH_HEAD,
	L4D2_ACT_FLINCH_CHEST,
	L4D2_ACT_FLINCH_STOMACH,
	L4D2_ACT_FLINCH_LEFTARM,
	L4D2_ACT_FLINCH_RIGHTARM,
	L4D2_ACT_FLINCH_LEFTLEG,
	L4D2_ACT_FLINCH_RIGHTLEG,
	L4D2_ACT_FLINCH_PHYSICS,
	L4D2_ACT_FLINCH_HEAD_BACK,
	L4D2_ACT_FLINCH_CHEST_BACK,
	L4D2_ACT_FLINCH_STOMACH_BACK,
	L4D2_ACT_FLINCH_CROUCH_FRONT,
	L4D2_ACT_FLINCH_CROUCH_BACK,
	L4D2_ACT_FLINCH_CROUCH_LEFT,
	L4D2_ACT_FLINCH_CROUCH_RIGHT,
	L4D2_ACT_IDLE_ON_FIRE,
	L4D2_ACT_WALK_ON_FIRE,
	L4D2_ACT_RUN_ON_FIRE,
	L4D2_ACT_RAPPEL_LOOP,
	L4D2_ACT_180_LEFT,
	L4D2_ACT_180_RIGHT,
	L4D2_ACT_90_LEFT,
	L4D2_ACT_90_RIGHT,
	L4D2_ACT_STEP_LEFT,
	L4D2_ACT_STEP_RIGHT,
	L4D2_ACT_STEP_BACK,
	L4D2_ACT_STEP_FORE,
	L4D2_ACT_GESTURE_RANGE_ATTACK1,
	L4D2_ACT_GESTURE_RANGE_ATTACK2,
	L4D2_ACT_GESTURE_MELEE_ATTACK1,
	L4D2_ACT_GESTURE_MELEE_ATTACK2,
	L4D2_ACT_GESTURE_RANGE_ATTACK1_LOW,
	L4D2_ACT_GESTURE_RANGE_ATTACK2_LOW,
	L4D2_ACT_MELEE_ATTACK_SWING_GESTURE,
	L4D2_ACT_GESTURE_SMALL_FLINCH,
	L4D2_ACT_GESTURE_BIG_FLINCH,
	L4D2_ACT_GESTURE_FLINCH_BLAST,
	L4D2_ACT_GESTURE_FLINCH_BLAST_SHOTGUN,
	L4D2_ACT_GESTURE_FLINCH_BLAST_DAMAGED,
	L4D2_ACT_GESTURE_FLINCH_BLAST_DAMAGED_SHOTGUN,
	L4D2_ACT_GESTURE_FLINCH_HEAD,
	L4D2_ACT_GESTURE_FLINCH_CHEST,
	L4D2_ACT_GESTURE_FLINCH_STOMACH,
	L4D2_ACT_GESTURE_FLINCH_LEFTARM,
	L4D2_ACT_GESTURE_FLINCH_RIGHTARM,
	L4D2_ACT_GESTURE_FLINCH_LEFTLEG,
	L4D2_ACT_GESTURE_FLINCH_RIGHTLEG,
	L4D2_ACT_GESTURE_TURN_LEFT,
	L4D2_ACT_GESTURE_TURN_RIGHT,
	L4D2_ACT_GESTURE_TURN_LEFT45,
	L4D2_ACT_GESTURE_TURN_RIGHT45,
	L4D2_ACT_GESTURE_TURN_LEFT90,
	L4D2_ACT_GESTURE_TURN_RIGHT90,
	L4D2_ACT_GESTURE_TURN_LEFT45_FLAT,
	L4D2_ACT_GESTURE_TURN_RIGHT45_FLAT,
	L4D2_ACT_GESTURE_TURN_LEFT90_FLAT,
	L4D2_ACT_GESTURE_TURN_RIGHT90_FLAT,
	L4D2_ACT_BARNACLE_HIT,
	L4D2_ACT_BARNACLE_PULL,
	L4D2_ACT_BARNACLE_CHOMP,
	L4D2_ACT_BARNACLE_CHEW,
	L4D2_ACT_DO_NOT_DISTURB,
	L4D2_ACT_SPECIFIC_SEQUENCE,
	L4D2_ACT_VM_DEPLOY,
	L4D2_ACT_VM_RELOAD_EMPTY,
	L4D2_ACT_VM_DRAW,
	L4D2_ACT_VM_HOLSTER,
	L4D2_ACT_VM_IDLE,
	L4D2_ACT_VM_FIDGET,
	L4D2_ACT_VM_PULLBACK,
	L4D2_ACT_VM_PULLBACK_HIGH,
	L4D2_ACT_VM_PULLBACK_LOW,
	L4D2_ACT_VM_THROW,
	L4D2_ACT_VM_DROP,
	L4D2_ACT_VM_PULLPIN,
	L4D2_ACT_VM_PRIMARYATTACK,
	L4D2_ACT_VM_SECONDARYATTACK,
	L4D2_ACT_VM_RELOAD,
	L4D2_ACT_VM_DRYFIRE,
	L4D2_ACT_VM_HITLEFT,
	L4D2_ACT_VM_HITLEFT2,
	L4D2_ACT_VM_HITRIGHT,
	L4D2_ACT_VM_HITRIGHT2,
	L4D2_ACT_VM_HITCENTER,
	L4D2_ACT_VM_HITCENTER2,
	L4D2_ACT_VM_MISSLEFT,
	L4D2_ACT_VM_MISSLEFT2,
	L4D2_ACT_VM_MISSRIGHT,
	L4D2_ACT_VM_MISSRIGHT2,
	L4D2_ACT_VM_MISSCENTER,
	L4D2_ACT_VM_MISSCENTER2,
	L4D2_ACT_VM_HAULBACK,
	L4D2_ACT_VM_SWINGHARD,
	L4D2_ACT_VM_SWINGMISS,
	L4D2_ACT_VM_SWINGHIT,
	L4D2_ACT_VM_IDLE_TO_LOWERED,
	L4D2_ACT_VM_IDLE_LOWERED,
	L4D2_ACT_VM_LOWERED_TO_IDLE,
	L4D2_ACT_VM_RECOIL1,
	L4D2_ACT_VM_RECOIL2,
	L4D2_ACT_VM_RECOIL3,
	L4D2_ACT_VM_PICKUP,
	L4D2_ACT_VM_RELEASE,
	L4D2_ACT_VM_MAUL_LOOP,
	L4D2_ACT_VM_ATTACH_SILENCER,
	L4D2_ACT_VM_DETACH_SILENCER,
	L4D2_ACT_SLAM_STICKWALL_IDLE,
	L4D2_ACT_SLAM_STICKWALL_ND_IDLE,
	L4D2_ACT_SLAM_STICKWALL_ATTACH,
	L4D2_ACT_SLAM_STICKWALL_ATTACH2,
	L4D2_ACT_SLAM_STICKWALL_ND_ATTACH,
	L4D2_ACT_SLAM_STICKWALL_ND_ATTACH2,
	L4D2_ACT_SLAM_STICKWALL_DETONATE,
	L4D2_ACT_SLAM_STICKWALL_DETONATOR_HOLSTER,
	L4D2_ACT_SLAM_STICKWALL_DRAW,
	L4D2_ACT_SLAM_STICKWALL_ND_DRAW,
	L4D2_ACT_SLAM_STICKWALL_TO_THROW,
	L4D2_ACT_SLAM_STICKWALL_TO_THROW_ND,
	L4D2_ACT_SLAM_STICKWALL_TO_TRIPMINE_ND,
	L4D2_ACT_SLAM_THROW_IDLE,
	L4D2_ACT_SLAM_THROW_ND_IDLE,
	L4D2_ACT_SLAM_THROW_THROW,
	L4D2_ACT_SLAM_THROW_THROW2,
	L4D2_ACT_SLAM_THROW_THROW_ND,
	L4D2_ACT_SLAM_THROW_THROW_ND2,
	L4D2_ACT_SLAM_THROW_DRAW,
	L4D2_ACT_SLAM_THROW_ND_DRAW,
	L4D2_ACT_SLAM_THROW_TO_STICKWALL,
	L4D2_ACT_SLAM_THROW_TO_STICKWALL_ND,
	L4D2_ACT_SLAM_THROW_DETONATE,
	L4D2_ACT_SLAM_THROW_DETONATOR_HOLSTER,
	L4D2_ACT_SLAM_THROW_TO_TRIPMINE_ND,
	L4D2_ACT_SLAM_TRIPMINE_IDLE,
	L4D2_ACT_SLAM_TRIPMINE_DRAW,
	L4D2_ACT_SLAM_TRIPMINE_ATTACH,
	L4D2_ACT_SLAM_TRIPMINE_ATTACH2,
	L4D2_ACT_SLAM_TRIPMINE_TO_STICKWALL_ND,
	L4D2_ACT_SLAM_TRIPMINE_TO_THROW_ND,
	L4D2_ACT_SLAM_DETONATOR_IDLE,
	L4D2_ACT_SLAM_DETONATOR_DRAW,
	L4D2_ACT_SLAM_DETONATOR_DETONATE,
	L4D2_ACT_SLAM_DETONATOR_HOLSTER,
	L4D2_ACT_SLAM_DETONATOR_STICKWALL_DRAW,
	L4D2_ACT_SLAM_DETONATOR_THROW_DRAW,
	L4D2_ACT_SHOTGUN_RELOAD_START,
	L4D2_ACT_SHOTGUN_RELOAD_FINISH,
	L4D2_ACT_SHOTGUN_PUMP,
	L4D2_ACT_SMG2_IDLE2,
	L4D2_ACT_SMG2_FIRE2,
	L4D2_ACT_SMG2_DRAW2,
	L4D2_ACT_SMG2_RELOAD2,
	L4D2_ACT_SMG2_DRYFIRE2,
	L4D2_ACT_SMG2_TOAUTO,
	L4D2_ACT_SMG2_TOBURST,
	L4D2_ACT_PHYSCANNON_UPGRADE,
	L4D2_ACT_RANGE_ATTACK_AR1,
	L4D2_ACT_RANGE_ATTACK_AR2,
	L4D2_ACT_RANGE_ATTACK_AR2_LOW,
	L4D2_ACT_RANGE_ATTACK_AR2_GRENADE,
	L4D2_ACT_RANGE_ATTACK_HMG1,
	L4D2_ACT_RANGE_ATTACK_ML,
	L4D2_ACT_RANGE_ATTACK_SMG1,
	L4D2_ACT_RANGE_ATTACK_SMG1_LOW,
	L4D2_ACT_RANGE_ATTACK_SMG2,
	L4D2_ACT_RANGE_ATTACK_SHOTGUN,
	L4D2_ACT_RANGE_ATTACK_SHOTGUN_LOW,
	L4D2_ACT_RANGE_ATTACK_PISTOL,
	L4D2_ACT_RANGE_ATTACK_PISTOL_LOW,
	L4D2_ACT_RANGE_ATTACK_SLAM,
	L4D2_ACT_RANGE_ATTACK_TRIPWIRE,
	L4D2_ACT_RANGE_ATTACK_THROW,
	L4D2_ACT_RANGE_ATTACK_SNIPER_RIFLE,
	L4D2_ACT_RANGE_ATTACK_RPG,
	L4D2_ACT_MELEE_ATTACK_SWING,
	L4D2_ACT_RANGE_AIM_LOW,
	L4D2_ACT_RANGE_AIM_SMG1_LOW,
	L4D2_ACT_RANGE_AIM_PISTOL_LOW,
	L4D2_ACT_RANGE_AIM_AR2_LOW,
	L4D2_ACT_COVER_PISTOL_LOW,
	L4D2_ACT_COVER_SMG1_LOW,
	L4D2_ACT_GESTURE_RANGE_ATTACK_AR1,
	L4D2_ACT_GESTURE_RANGE_ATTACK_AR2,
	L4D2_ACT_GESTURE_RANGE_ATTACK_AR2_GRENADE,
	L4D2_ACT_GESTURE_RANGE_ATTACK_HMG1,
	L4D2_ACT_GESTURE_RANGE_ATTACK_ML,
	L4D2_ACT_GESTURE_RANGE_ATTACK_SMG1,
	L4D2_ACT_GESTURE_RANGE_ATTACK_SMG1_LOW,
	L4D2_ACT_GESTURE_RANGE_ATTACK_SMG2,
	L4D2_ACT_GESTURE_RANGE_ATTACK_SHOTGUN,
	L4D2_ACT_GESTURE_RANGE_ATTACK_PISTOL,
	L4D2_ACT_GESTURE_RANGE_ATTACK_PISTOL_LOW,
	L4D2_ACT_GESTURE_RANGE_ATTACK_SLAM,
	L4D2_ACT_GESTURE_RANGE_ATTACK_TRIPWIRE,
	L4D2_ACT_GESTURE_RANGE_ATTACK_THROW,
	L4D2_ACT_GESTURE_RANGE_ATTACK_SNIPER_RIFLE,
	L4D2_ACT_GESTURE_MELEE_ATTACK_SWING,
	L4D2_ACT_IDLE_RIFLE,
	L4D2_ACT_IDLE_SMG1,
	L4D2_ACT_IDLE_ANGRY_SMG1,
	L4D2_ACT_IDLE_PISTOL,
	L4D2_ACT_IDLE_ANGRY_PISTOL,
	L4D2_ACT_IDLE_ANGRY_SHOTGUN,
	L4D2_ACT_IDLE_STEALTH_PISTOL,
	L4D2_ACT_IDLE_PACKAGE,
	L4D2_ACT_WALK_PACKAGE,
	L4D2_ACT_IDLE_SUITCASE,
	L4D2_ACT_WALK_SUITCASE,
	L4D2_ACT_IDLE_SMG1_RELAXED,
	L4D2_ACT_IDLE_SMG1_STIMULATED,
	L4D2_ACT_WALK_RIFLE_RELAXED,
	L4D2_ACT_RUN_RIFLE_RELAXED,
	L4D2_ACT_WALK_RIFLE_STIMULATED,
	L4D2_ACT_RUN_RIFLE_STIMULATED,
	L4D2_ACT_IDLE_AIM_RIFLE_STIMULATED,
	L4D2_ACT_WALK_AIM_RIFLE_STIMULATED,
	L4D2_ACT_RUN_AIM_RIFLE_STIMULATED,
	L4D2_ACT_IDLE_SHOTGUN_RELAXED,
	L4D2_ACT_IDLE_SHOTGUN_STIMULATED,
	L4D2_ACT_IDLE_SHOTGUN_AGITATED,
	L4D2_ACT_WALK_ANGRY,
	L4D2_ACT_POLICE_HARASS1,
	L4D2_ACT_POLICE_HARASS2,
	L4D2_ACT_IDLE_MANNEDGUN,
	L4D2_ACT_IDLE_MELEE,
	L4D2_ACT_IDLE_ANGRY_MELEE,
	L4D2_ACT_IDLE_RPG_RELAXED,
	L4D2_ACT_IDLE_RPG,
	L4D2_ACT_IDLE_ANGRY_RPG,
	L4D2_ACT_COVER_LOW_RPG,
	L4D2_ACT_WALK_RPG,
	L4D2_ACT_RUN_RPG,
	L4D2_ACT_WALK_CROUCH_RPG,
	L4D2_ACT_RUN_CROUCH_RPG,
	L4D2_ACT_WALK_RPG_RELAXED,
	L4D2_ACT_RUN_RPG_RELAXED,
	L4D2_ACT_WALK_RIFLE,
	L4D2_ACT_WALK_AIM_RIFLE,
	L4D2_ACT_WALK_CROUCH_RIFLE,
	L4D2_ACT_WALK_CROUCH_AIM_RIFLE,
	L4D2_ACT_RUN_RIFLE,
	L4D2_ACT_RUN_AIM_RIFLE,
	L4D2_ACT_RUN_CROUCH_RIFLE,
	L4D2_ACT_RUN_CROUCH_AIM_RIFLE,
	L4D2_ACT_RUN_STEALTH_PISTOL,
	L4D2_ACT_WALK_AIM_SHOTGUN,
	L4D2_ACT_RUN_AIM_SHOTGUN,
	L4D2_ACT_WALK_PISTOL,
	L4D2_ACT_RUN_PISTOL,
	L4D2_ACT_WALK_AIM_PISTOL,
	L4D2_ACT_RUN_AIM_PISTOL,
	L4D2_ACT_WALK_STEALTH_PISTOL,
	L4D2_ACT_WALK_AIM_STEALTH_PISTOL,
	L4D2_ACT_RUN_AIM_STEALTH_PISTOL,
	L4D2_ACT_RELOAD_PISTOL,
	L4D2_ACT_RELOAD_PISTOL_LOW,
	L4D2_ACT_RELOAD_SMG1,
	L4D2_ACT_RELOAD_SMG1_LOW,
	L4D2_ACT_RELOAD_SHOTGUN,
	L4D2_ACT_RELOAD_SHOTGUN_LOW,
	L4D2_ACT_GESTURE_RELOAD,
	L4D2_ACT_GESTURE_RELOAD_PISTOL,
	L4D2_ACT_GESTURE_RELOAD_SMG1,
	L4D2_ACT_GESTURE_RELOAD_SHOTGUN,
	L4D2_ACT_BUSY_LEAN_LEFT,
	L4D2_ACT_BUSY_LEAN_LEFT_ENTRY,
	L4D2_ACT_BUSY_LEAN_LEFT_EXIT,
	L4D2_ACT_BUSY_LEAN_BACK,
	L4D2_ACT_BUSY_LEAN_BACK_ENTRY,
	L4D2_ACT_BUSY_LEAN_BACK_EXIT,
	L4D2_ACT_BUSY_SIT_GROUND,
	L4D2_ACT_BUSY_SIT_GROUND_ENTRY,
	L4D2_ACT_BUSY_SIT_GROUND_EXIT,
	L4D2_ACT_BUSY_SIT_CHAIR,
	L4D2_ACT_BUSY_SIT_CHAIR_ENTRY,
	L4D2_ACT_BUSY_SIT_CHAIR_EXIT,
	L4D2_ACT_BUSY_STAND,
	L4D2_ACT_BUSY_QUEUE,
	L4D2_ACT_DUCK_DODGE,
	L4D2_ACT_DIE_BARNACLE_SWALLOW,
	L4D2_ACT_GESTURE_BARNACLE_STRANGLE,
	L4D2_ACT_PHYSCANNON_DETACH,
	L4D2_ACT_PHYSCANNON_ANIMATE,
	L4D2_ACT_PHYSCANNON_ANIMATE_PRE,
	L4D2_ACT_PHYSCANNON_ANIMATE_POST,
	L4D2_ACT_DIE_FRONTSIDE,
	L4D2_ACT_DIE_RIGHTSIDE,
	L4D2_ACT_DIE_BACKSIDE,
	L4D2_ACT_DIE_LEFTSIDE,
	L4D2_ACT_DIE_CROUCH_FRONTSIDE,
	L4D2_ACT_DIE_CROUCH_RIGHTSIDE,
	L4D2_ACT_DIE_CROUCH_BACKSIDE,
	L4D2_ACT_DIE_CROUCH_LEFTSIDE,
	L4D2_ACT_DIE_INCAP,
	L4D2_ACT_DIE_STANDING,
	L4D2_ACT_OPEN_DOOR,
	L4D2_ACT_DI_ALYX_ZOMBIE_MELEE,
	L4D2_ACT_DI_ALYX_ZOMBIE_TORSO_MELEE,
	L4D2_ACT_DI_ALYX_HEADCRAB_MELEE,
	L4D2_ACT_DI_ALYX_ANTLION,
	L4D2_ACT_DI_ALYX_ZOMBIE_SHOTGUN64,
	L4D2_ACT_DI_ALYX_ZOMBIE_SHOTGUN26,
	L4D2_ACT_READINESS_RELAXED_TO_STIMULATED,
	L4D2_ACT_READINESS_RELAXED_TO_STIMULATED_WALK,
	L4D2_ACT_READINESS_AGITATED_TO_STIMULATED,
	L4D2_ACT_READINESS_STIMULATED_TO_RELAXED,
	L4D2_ACT_READINESS_PISTOL_RELAXED_TO_STIMULATED,
	L4D2_ACT_READINESS_PISTOL_RELAXED_TO_STIMULATED_WALK,
	L4D2_ACT_READINESS_PISTOL_AGITATED_TO_STIMULATED,
	L4D2_ACT_READINESS_PISTOL_STIMULATED_TO_RELAXED,
	L4D2_ACT_IDLE_CARRY,
	L4D2_ACT_WALK_CARRY,
	L4D2_ACT_STARTDYING,
	L4D2_ACT_DYINGLOOP,
	L4D2_ACT_DYINGTODEAD,
	L4D2_ACT_RIDE_MANNED_GUN,
	L4D2_ACT_VM_SPRINT_ENTER,
	L4D2_ACT_VM_SPRINT_IDLE,
	L4D2_ACT_VM_SPRINT_LEAVE,
	L4D2_ACT_FIRE_START,
	L4D2_ACT_FIRE_LOOP,
	L4D2_ACT_FIRE_END,
	L4D2_ACT_CROUCHING_GRENADEIDLE,
	L4D2_ACT_CROUCHING_GRENADEREADY,
	L4D2_ACT_CROUCHING_PRIMARYATTACK,
	L4D2_ACT_OVERLAY_GRENADEIDLE,
	L4D2_ACT_OVERLAY_GRENADEREADY,
	L4D2_ACT_OVERLAY_PRIMARYATTACK,
	L4D2_ACT_OVERLAY_SHIELD_UP,
	L4D2_ACT_OVERLAY_SHIELD_DOWN,
	L4D2_ACT_OVERLAY_SHIELD_UP_IDLE,
	L4D2_ACT_OVERLAY_SHIELD_ATTACK,
	L4D2_ACT_OVERLAY_SHIELD_KNOCKBACK,
	L4D2_ACT_SHIELD_UP,
	L4D2_ACT_SHIELD_DOWN,
	L4D2_ACT_SHIELD_UP_IDLE,
	L4D2_ACT_SHIELD_ATTACK,
	L4D2_ACT_SHIELD_KNOCKBACK,
	L4D2_ACT_CROUCHING_SHIELD_UP,
	L4D2_ACT_CROUCHING_SHIELD_DOWN,
	L4D2_ACT_CROUCHING_SHIELD_UP_IDLE,
	L4D2_ACT_CROUCHING_SHIELD_ATTACK,
	L4D2_ACT_CROUCHING_SHIELD_KNOCKBACK,
	L4D2_ACT_TURNRIGHT45,
	L4D2_ACT_TURNLEFT45,
	L4D2_ACT_TURN,
	L4D2_ACT_OBJ_ASSEMBLING,
	L4D2_ACT_OBJ_DISMANTLING,
	L4D2_ACT_OBJ_STARTUP,
	L4D2_ACT_OBJ_RUNNING,
	L4D2_ACT_OBJ_IDLE,
	L4D2_ACT_OBJ_PLACING,
	L4D2_ACT_OBJ_DETERIORATING,
	L4D2_ACT_OBJ_UPGRADING,
	L4D2_ACT_DEPLOY,
	L4D2_ACT_DEPLOY_IDLE,
	L4D2_ACT_UNDEPLOY,
	L4D2_ACT_CROSSBOW_DRAW_UNLOADED,
	L4D2_ACT_GAUSS_SPINUP,
	L4D2_ACT_GAUSS_SPINCYCLE,
	L4D2_ACT_VM_PRIMARYATTACK_SILENCED,
	L4D2_ACT_VM_RELOAD_SILENCED,
	L4D2_ACT_VM_DRYFIRE_SILENCED,
	L4D2_ACT_VM_IDLE_SILENCED,
	L4D2_ACT_VM_DRAW_SILENCED,
	L4D2_ACT_VM_IDLE_EMPTY_LEFT,
	L4D2_ACT_VM_DRYFIRE_LEFT,
	L4D2_ACT_VM_IS_DRAW,
	L4D2_ACT_VM_IS_HOLSTER,
	L4D2_ACT_VM_IS_IDLE,
	L4D2_ACT_VM_IS_PRIMARYATTACK,
	L4D2_ACT_PLAYER_IDLE_FIRE,
	L4D2_ACT_PLAYER_CROUCH_FIRE,
	L4D2_ACT_PLAYER_CROUCH_WALK_FIRE,
	L4D2_ACT_PLAYER_WALK_FIRE,
	L4D2_ACT_PLAYER_RUN_FIRE,
	L4D2_ACT_IDLETORUN,
	L4D2_ACT_RUNTOIDLE,
	L4D2_ACT_VM_DRAW_DEPLOYED,
	L4D2_ACT_HL2MP_IDLE_MELEE,
	L4D2_ACT_HL2MP_RUN_MELEE,
	L4D2_ACT_HL2MP_IDLE_CROUCH_MELEE,
	L4D2_ACT_HL2MP_WALK_CROUCH_MELEE,
	L4D2_ACT_HL2MP_GESTURE_RANGE_ATTACK_MELEE,
	L4D2_ACT_HL2MP_GESTURE_RELOAD_MELEE,
	L4D2_ACT_HL2MP_JUMP_MELEE,
	L4D2_ACT_VM_SHRIEK,
	L4D2_ACT_VM_VOMIT,
	L4D2_ACT_VM_COUGH,
	L4D2_ACT_VM_LUNGE,
	L4D2_ACT_VM_PUMMEL_ATTACK,
	L4D2_ACT_VM_IDLE2REV,
	L4D2_ACT_VM_REV2IDLE,
	L4D2_ACT_IDLE_INJURED,
	L4D2_ACT_IDLE_INCAP,
	L4D2_ACT_WALK_INJURED,
	L4D2_ACT_RUN_INJURED,
	L4D2_ACT_IDLE_CALM,
	L4D2_ACT_WALK_CALM,
	L4D2_ACT_RUN_CALM,
	L4D2_ACT_JUMP_SHOTGUN,
	L4D2_ACT_JUMP_RIFLE,
	L4D2_ACT_JUMP_SMG,
	L4D2_ACT_JUMP_PISTOL,
	L4D2_ACT_JUMP_DUAL_PISTOL,
	L4D2_ACT_JUMP_ITEM,
	L4D2_ACT_TERROR_HIT_BY_TANKPUNCH,
	L4D2_ACT_TERROR_IDLE_FALL_FROM_TANKPUNCH,
	L4D2_ACT_TERROR_TANKPUNCH_LAND,
	L4D2_ACT_TERROR_HIT_BY_CHARGER,
	L4D2_ACT_TERROR_IDLE_FALL_FROM_CHARGERHIT,
	L4D2_ACT_TERROR_CHARGERHIT_LAND_SLOW,
	L4D2_ACT_TERROR_CHARGER_PUMMELED,
	L4D2_ACT_TERROR_CARRIED,
	L4D2_ACT_TERROR_SLAMMED_WALL,
	L4D2_ACT_TERROR_SLAMMED_GROUND,
	L4D2_ACT_TERROR_CHARGER_POUNDED_NORTH,
	L4D2_ACT_TERROR_CHARGER_POUNDED_UP,
	L4D2_ACT_TERROR_CHARGER_POUNDED_INCAP,
	L4D2_ACT_TERROR_CHARGER_POUNDED_DOWN,
	L4D2_ACT_TERROR_CHARGER_PUMMEL,
	L4D2_ACT_TERROR_SLAM_GROUND,
	L4D2_ACT_TERROR_CHARGER_POUND_NORTH,
	L4D2_ACT_TERROR_CHARGER_POUND_UP,
	L4D2_ACT_TERROR_CHARGER_POUND_DOWN_PRODUCER,
	L4D2_ACT_TERROR_CHARGER_POUND_DOWN_COACH,
	L4D2_ACT_TERROR_CHARGER_POUND_DOWN,
	L4D2_ACT_TERROR_PUMMELED_LOOP,
	L4D2_ACT_TERROR_SPITTER_SPIT,
	L4D2_ACT_TERROR_HEAL_SELF,
	L4D2_ACT_TERROR_HEAL_FRIEND,
	L4D2_ACT_TERROR_HEAL_INCAPACITATED,
	L4D2_ACT_TERROR_CROUCH_HEAL_SELF,
	L4D2_ACT_TERROR_CROUCH_HEAL_FRIEND,
	L4D2_ACT_TERROR_CROUCH_HEAL_INCAPACITATED,
	L4D2_ACT_TERROR_HEAL_INCAPACITATED_ABOVE,
	L4D2_ACT_TERROR_CROUCH_HEAL_INCAPACITATED_ABOVE,
	L4D2_ACT_TERROR_USE_PILLS,
	L4D2_ACT_TERROR_USE_ADRENALINE,
	L4D2_ACT_TERROR_USE_ADRENALINE_CROUCHING,
	L4D2_ACT_TERROR_USE_DEFIBRILLATOR,
	L4D2_ACT_TERROR_CROUCH_USE_DEFIBRILLATOR,
	L4D2_ACT_TERROR_REVIVE_FROM_DEATH,
	L4D2_ACT_TERROR_DEFIBRILLATOR_SHOCK,
	L4D2_ACT_TERROR_USE_UPGRADEPACK,
	L4D2_ACT_TERROR_CROUCH_USE_UPGRADEPACK,
	L4D2_ACT_TERROR_USE_GAS_CAN,
	L4D2_ACT_TERROR_USE_COLA,
	L4D2_ACT_TERROR_IDLE_NEUTRAL,
	L4D2_ACT_TERROR_IDLE_ALERT,
	L4D2_ACT_TERROR_IDLE_INTENSE,
	L4D2_ACT_TERROR_IDLE_ALERT_INJURED_AHEAD,
	L4D2_ACT_TERROR_IDLE_ALERT_AHEAD,
	L4D2_ACT_TERROR_IDLE_ALERT_INJURED_BEHIND,
	L4D2_ACT_TERROR_IDLE_ALERT_BEHIND,
	L4D2_ACT_TERROR_IDLE_ALERT_INJURED_LEFT,
	L4D2_ACT_TERROR_IDLE_ALERT_LEFT,
	L4D2_ACT_TERROR_IDLE_ALERT_INJURED_RIGHT,
	L4D2_ACT_TERROR_IDLE_ALERT_RIGHT,
	L4D2_ACT_TERROR_IDLE_ACQUIRE,
	L4D2_ACT_TERROR_LEAN_FORWARD_IDLE,
	L4D2_ACT_TERROR_LEAN_BACKWARD_IDLE,
	L4D2_ACT_TERROR_LEAN_LEFTWARD_IDLE,
	L4D2_ACT_TERROR_LEAN_RIGHTWARD_IDLE,
	L4D2_ACT_TERROR_FIDGET,
	L4D2_ACT_TERROR_NEUTRAL_TO_ALERT,
	L4D2_ACT_TERROR_ALERT_TO_NEUTRAL,
	L4D2_ACT_TERROR_FACE_LEFT_NEUTRAL,
	L4D2_ACT_TERROR_FACE_LEFT_ALERT,
	L4D2_ACT_TERROR_FACE_LEFT_INTENSE,
	L4D2_ACT_TERROR_FACE_RIGHT_NEUTRAL,
	L4D2_ACT_TERROR_FACE_RIGHT_ALERT,
	L4D2_ACT_TERROR_FACE_RIGHT_INTENSE,
	L4D2_ACT_TERROR_ABOUT_FACE_NEUTRAL,
	L4D2_ACT_TERROR_ABOUT_FACE_ALERT,
	L4D2_ACT_TERROR_ABOUT_FACE_INTENSE,
	L4D2_ACT_TERROR_SHAMBLE,
	L4D2_ACT_TERROR_WALK_NEUTRAL,
	L4D2_ACT_TERROR_WALK_ALERT,
	L4D2_ACT_TERROR_WALK_INTENSE,
	L4D2_ACT_TERROR_RUN_NEUTRAL,
	L4D2_ACT_TERROR_RUN_ALERT,
	L4D2_ACT_TERROR_RUN_INTENSE,
	L4D2_ACT_TERROR_RUN_ON_FIRE_INTENSE,
	L4D2_ACT_TERROR_RUN_INTENSE_TO_STAND_ALERT,
	L4D2_ACT_TERROR_CROUCH_IDLE_NEUTRAL,
	L4D2_ACT_TERROR_CROUCH_IDLE_ALERT,
	L4D2_ACT_TERROR_CROUCH_IDLE_INTENSE,
	L4D2_ACT_TERROR_CROUCH_WALK_NEUTRAL,
	L4D2_ACT_TERROR_CROUCH_WALK_ALERT,
	L4D2_ACT_TERROR_CROUCH_WALK_INTENSE,
	L4D2_ACT_TERROR_CROUCH_RUN_NEUTRAL,
	L4D2_ACT_TERROR_CROUCH_RUN_ALERT,
	L4D2_ACT_TERROR_CROUCH_RUN_INTENSE,
	L4D2_ACT_TERROR_CRAWL_RUN,
	L4D2_ACT_TERROR_IDLE_ON_FIRE,
	L4D2_ACT_TERROR_WALK_ON_FIRE,
	L4D2_ACT_TERROR_RUN_ON_FIRE,
	L4D2_ACT_TERROR_ATTACK,
	L4D2_ACT_TERROR_ATTACK_CONTINUOUSLY,
	L4D2_ACT_TERROR_ATTACK_LOW,
	L4D2_ACT_TERROR_ATTACK_LOW_CONTINUOUSLY,
	L4D2_ACT_TERROR_ATTACK_DOOR,
	L4D2_ACT_TERROR_ATTACK_DOOR_CONTINUOUSLY,
	L4D2_ACT_TERROR_UNABLE_TO_REACH_TARGET,
	L4D2_ACT_TERROR_REACH_THROUGH_DOOR,
	L4D2_ACT_TERROR_SHOVED_FORWARD,
	L4D2_ACT_TERROR_SHOVED_BACKWARD,
	L4D2_ACT_TERROR_SHOVED_LEFTWARD,
	L4D2_ACT_TERROR_SHOVED_RIGHTWARD,
	L4D2_ACT_TERROR_SHOVED_FORWARD_CHAINSAW,
	L4D2_ACT_TERROR_SHOVED_BACKWARD_CHAINSAW,
	L4D2_ACT_TERROR_SHOVED_LEFTWARD_CHAINSAW,
	L4D2_ACT_TERROR_SHOVED_RIGHTWARD_CHAINSAW,
	L4D2_ACT_TERROR_SHOVED_FORWARD_BAT,
	L4D2_ACT_TERROR_SHOVED_BACKWARD_BAT,
	L4D2_ACT_TERROR_SHOVED_LEFTWARD_BAT,
	L4D2_ACT_TERROR_SHOVED_RIGHTWARD_BAT,
	L4D2_ACT_TERROR_SHOVED_FORWARD_MELEE,
	L4D2_ACT_TERROR_SHOVED_BACKWARD_MELEE,
	L4D2_ACT_TERROR_SHOVED_LEFTWARD_MELEE,
	L4D2_ACT_TERROR_SHOVED_RIGHTWARD_MELEE,
	L4D2_ACT_TERROR_SHOVED_BACKWARD_INTO_WALL,
	L4D2_ACT_TERROR_SHOVED_FORWARD_INTO_WALL,
	L4D2_ACT_TERROR_SHOVED_LEFTWARD_INTO_WALL,
	L4D2_ACT_TERROR_SHOVED_RIGHTWARD_INTO_WALL,
	L4D2_ACT_TERROR_SHOVED_BACKWARD_FROM_SIT,
	L4D2_ACT_TERROR_SHOVED_RIGHTWARD_FROM_SIT,
	L4D2_ACT_TERROR_SHOVED_LEFTWARD_FROM_SIT,
	L4D2_ACT_TERROR_TUGGED_FORWARD,
	L4D2_ACT_TERROR_TUGGED_BACKWARD,
	L4D2_ACT_TERROR_TUGGED_LEFTWARD,
	L4D2_ACT_TERROR_TUGGED_RIGHTWARD,
	L4D2_ACT_TERROR_SIT_IDLE,
	L4D2_ACT_TERROR_SIT_FROM_STAND,
	L4D2_ACT_TERROR_SIT_TO_STAND,
	L4D2_ACT_TERROR_SIT_TO_STAND_ALERT,
	L4D2_ACT_TERROR_SIT_TO_LIE,
	L4D2_ACT_TERROR_LIE_IDLE,
	L4D2_ACT_TERROR_LIE_FROM_STAND,
	L4D2_ACT_TERROR_LIE_TO_STAND,
	L4D2_ACT_TERROR_LIE_TO_STAND_ALERT,
	L4D2_ACT_TERROR_LIE_TO_SIT,
	L4D2_ACT_TERROR_JUMP,
	L4D2_ACT_TERROR_JUMP_UP_TO_LEDGE,
	L4D2_ACT_TERROR_JUMP_DOWN_FROM_LEDGE,
	L4D2_ACT_TERROR_JUMP_OVER_GAP,
	L4D2_ACT_TERROR_JUMP_LANDING,
	L4D2_ACT_TERROR_JUMP_LANDING_HARD,
	L4D2_ACT_TERROR_JUMP_LANDING_NEUTRAL,
	L4D2_ACT_TERROR_JUMP_LANDING_HARD_NEUTRAL,
	L4D2_ACT_TERROR_FALL,
	L4D2_ACT_TERROR_DIE_FROM_STAND,
	L4D2_ACT_TERROR_DIE_FROM_CROUCH,
	L4D2_ACT_TERROR_DIE_WHILE_RUNNING,
	L4D2_ACT_TERROR_DIE_BACKWARD_FROM_SHOTGUN,
	L4D2_ACT_TERROR_DIE_FORWARD_FROM_SHOTGUN,
	L4D2_ACT_TERROR_DIE_LEFTWARD_FROM_SHOTGUN,
	L4D2_ACT_TERROR_DIE_RIGHTWARD_FROM_SHOTGUN,
	L4D2_ACT_BLUDGEON_DEATH_BACK,
	L4D2_ACT_BLUDGEON_DEATH_FORWARD,
	L4D2_ACT_BLUDGEON_DEATH_LEFT,
	L4D2_ACT_BLUDGEON_DEATH_RIGHT,
	L4D2_ACT_SLICING_DEATH_BACK,
	L4D2_ACT_SLICING_DEATH_FORWARD,
	L4D2_ACT_SLICING_DEATH_LEFT,
	L4D2_ACT_SLICING_DEATH_RIGHT,
	L4D2_ACT_TERROR_WITCH_ANGRY,
	L4D2_ACT_TERROR_WITCH_ANGRY_HIGH,
	L4D2_ACT_TERROR_WITCH_IDLE,
	L4D2_ACT_TERROR_WITCH_IDLE_PRE_RETREAT,
	L4D2_ACT_TERROR_WITCH_RETREAT,
	L4D2_ACT_TERROR_WITCH_KILL_DISPLAY,
	L4D2_ACT_TERROR_WITCH_KILL_LOOP,
	L4D2_ACT_TERROR_WITCH_WANDER_WALK,
	L4D2_ACT_TERROR_WITCH_WANDER_IDLE,
	L4D2_ACT_TERROR_WITCH_WANDER_ACQUIRE,
	L4D2_ACT_TERROR_TUG,
	L4D2_ACT_TERROR_FLINCH,
	L4D2_ACT_TERROR_FLINCH_LEDGE,
	L4D2_ACT_SECONDARYATTACK,
	L4D2_ACT_TERROR_INCAP_CRAWL,
	L4D2_ACT_TERROR_INCAP_TO_STAND,
	L4D2_ACT_TERROR_INCAP_TO_CROUCH,
	L4D2_ACT_TERROR_ITEM_PICKUP,
	L4D2_ACT_IDLE_INCAP_PISTOL,
	L4D2_ACT_IDLE_INCAP_ELITES,
	L4D2_ACT_FALL,
	L4D2_ACT_CALL_FOR_RESCUE,
	L4D2_ACT_PUSH,
	L4D2_ACT_IDLE_MINIGUN,
	L4D2_ACT_PRIMARYATTACK_MINIGUN,
	L4D2_ACT_GEST_HEAD_NOD,
	L4D2_ACT_GEST_HEAD_YES,
	L4D2_ACT_GEST_HEAD_NO,
	L4D2_ACT_TERROR_LEDGE_CLIMB,
	L4D2_ACT_TERROR_LEDGE_CLIMB_TO_CROUCH,
	L4D2_ACT_TERROR_FALL_GRAB_LEDGE,
	L4D2_ACT_TERROR_LEDGE_HANG_FIRM,
	L4D2_ACT_TERROR_LEDGE_HANG_WEAK,
	L4D2_ACT_TERROR_LEDGE_HANG_DANGLE,
	L4D2_ACT_TERROR_IDLE_LADDER,
	L4D2_ACT_TERROR_LADDER_DISMOUNT,
	L4D2_ACT_TERROR_CLIMB_24_FROM_STAND,
	L4D2_ACT_TERROR_CLIMB_36_FROM_STAND,
	L4D2_ACT_TERROR_CLIMB_38_FROM_STAND,
	L4D2_ACT_TERROR_CLIMB_48_FROM_STAND,
	L4D2_ACT_TERROR_CLIMB_50_FROM_STAND,
	L4D2_ACT_TERROR_CLIMB_60_FROM_STAND,
	L4D2_ACT_TERROR_CLIMB_70_FROM_STAND,
	L4D2_ACT_TERROR_CLIMB_72_FROM_STAND,
	L4D2_ACT_TERROR_CLIMB_84_FROM_STAND,
	L4D2_ACT_TERROR_CLIMB_96_FROM_STAND,
	L4D2_ACT_TERROR_CLIMB_108_FROM_STAND,
	L4D2_ACT_TERROR_CLIMB_115_FROM_STAND,
	L4D2_ACT_TERROR_CLIMB_120_FROM_STAND,
	L4D2_ACT_TERROR_CLIMB_130_FROM_STAND,
	L4D2_ACT_TERROR_CLIMB_132_FROM_STAND,
	L4D2_ACT_TERROR_CLIMB_144_FROM_STAND,
	L4D2_ACT_TERROR_CLIMB_150_FROM_STAND,
	L4D2_ACT_TERROR_CLIMB_156_FROM_STAND,
	L4D2_ACT_TERROR_CLIMB_166_FROM_STAND,
	L4D2_ACT_TERROR_CLIMB_168_FROM_STAND,
	L4D2_ACT_TERROR_HUNTER_LUNGE_INTO_SURVIVOR,
	L4D2_ACT_TERROR_HUNTER_LUNGE,
	L4D2_ACT_TERROR_HUNTER_LUNGE_WHILE_RUNNING,
	L4D2_ACT_TERROR_HUNTER_LANDING_HARD,
	L4D2_ACT_TERROR_HUNTER_LUNGE_OFF_WALL_SPIN_RIGHT,
	L4D2_ACT_TERROR_HUNTER_LUNGE_OFF_WALL_SPIN_LEFT,
	L4D2_ACT_TERROR_HUNTER_LUNGE_OFF_WALL_BACK,
	L4D2_ACT_TERROR_HUNTER_LUNGE_IDLE,
	L4D2_ACT_TERROR_HUNTER_LUNGE_ONTO_WALL,
	L4D2_ACT_TERROR_HUNTER_POUNCE,
	L4D2_ACT_TERROR_HUNTER_POUNCE_IDLE,
	L4D2_ACT_TERROR_SMOKER_PREPARE_TONGUE_LAUNCH,
	L4D2_ACT_TERROR_SMOKER_SENDING_OUT_TONGUE,
	L4D2_ACT_TERROR_SMOKER_SENDING_OUT_TONGUE_IDLE,
	L4D2_ACT_TERROR_SMOKER_REELING_IN_TONGUE,
	L4D2_ACT_TERROR_SMOKER_REELING_IN_TONGUE_IDLE,
	L4D2_ACT_TERROR_SMOKER_CRITICAL_ATTACK,
	L4D2_ACT_TERROR_SMOKER_CRITICAL_ATTACK_IDLE,
	L4D2_ACT_TERROR_SMOKER_END_TONGUE_ATTACK,
	L4D2_ACT_TERROR_RUN_LEAKER,
	L4D2_ACT_TERROR_CROUCH_LEAKER,
	L4D2_ACT_TERROR_CROUCHIDLE_LEAKER,
	L4D2_ACT_TERROR_GUARD,
	L4D2_ACT_HULK_THROW,
	L4D2_ACT_TANK_OVERHEAD_THROW,
	L4D2_ACT_HULK_ATTACK_LOW,
	L4D2_ACT_TERROR_HUNTER_POUNCE_MELEE,
	L4D2_ACT_TERROR_HUNTER_POUNCE_KNOCKOFF_L,
	L4D2_ACT_TERROR_HUNTER_POUNCE_KNOCKOFF_R,
	L4D2_ACT_TERROR_HUNTER_POUNCE_KNOCKOFF_BACKWARD,
	L4D2_ACT_TERROR_HUNTER_POUNCE_KNOCKOFF_FORWARD,
	L4D2_ACT_TERROR_CHARGER_CHARGE,
	L4D2_ACT_IDLE_POUNCED,
	L4D2_ACT_TERROR_POUNCED_TO_STAND,
	L4D2_ACT_TERROR_INCAP_FROM_POUNCE,
	L4D2_ACT_TERROR_INCAP_FROM_TONGUE,
	L4D2_ACT_TERROR_IDLE_FALL_FROM_TONGUE,
	L4D2_ACT_TERROR_HANGING_FROM_TONGUE,
	L4D2_ACT_TERROR_HANGING_FROM_TONGUE_MALE,
	L4D2_ACT_TERROR_HANGING_FROM_TONGUE_FEMALE,
	L4D2_ACT_TERROR_STANDING_CHOKE_FROM_TONGUE,
	L4D2_ACT_TERROR_DRAGGING_FROM_TONGUE,
	L4D2_ACT_TERROR_DRAGGING_FROM_TONGUE_MALE,
	L4D2_ACT_TERROR_DRAGGING_FROM_TONGUE_FEMALE,
	L4D2_ACT_TERROR_DRAGGING_FROM_TONGUE_DEPLOY,
	L4D2_ACT_TERROR_CHOKING_TONGUE_GROUND,
	L4D2_ACT_TERROR_CHOKING_TONGUE_GROUND_MALE,
	L4D2_ACT_TERROR_CHOKING_TONGUE_GROUND_FEMALE,
	L4D2_ACT_TERROR_INCAP_FROM_TONGUE_GERMANY,
	L4D2_ACT_TERROR_HANGING_FROM_TONGUE_GERMANY,
	L4D2_ACT_TERROR_IDLE_FALL_FROM_TONGUE_GERMANY,
	L4D2_ACT_TERROR_STANDING_CHOKE_FROM_TONGUE_GERMANY,
	L4D2_ACT_TERROR_ATTACK_MOVING,
	L4D2_ACT_TERROR_TANKROCK_TO_STAND,
	L4D2_ACT_TERROR_HULK_VICTORY,
	L4D2_ACT_TERROR_HULK_VICTORY_B,
	L4D2_ACT_TERROR_RAGE_AT_ENEMY,
	L4D2_ACT_TERROR_RAGE_AT_KNOCKDOWN,
	L4D2_ACT_TERROR_SMASH_LEFT,
	L4D2_ACT_TERROR_SMASH_RIGHT,
	L4D2_ACT_TERROR_JOCKEY_RIDE,
	L4D2_ACT_TERROR_JOCKEY_RIDDEN,
	L4D2_ACT_VM_LUNGE_LAYER,
	L4D2_ACT_VM_LUNGE_PUSH,
	L4D2_ACT_VM_LUNGE_PUSH_LAYER,
	L4D2_ACT_VM_LUNGE_OFFWALL,
	L4D2_ACT_VM_LUNGE_OFFWALL_LAYER,
	L4D2_ACT_VM_LUNGE_POUNCE,
	L4D2_ACT_VM_LUNGE_POUNCE_LAYER,
	L4D2_ACT_VM_POUNCE,
	L4D2_ACT_VM_POUNCE_LAYER,
	L4D2_ACT_VM_VOMIT_LAYER,
	L4D2_ACT_VM_TONGUE,
	L4D2_ACT_VM_TONGUE_LAYER,
	L4D2_ACT_VM_BITE,
	L4D2_ACT_VM_BITE_LAYER,
	L4D2_ACT_VM_COUGH_LAYER,
	L4D2_ACT_VM_FIDGET_LAYER,
	L4D2_ACT_DOOR_OPEN,
	L4D2_ACT_DOOR_OPENFAIL,
	L4D2_ACT_DOOR_ANIMTOLOCK,
	L4D2_ACT_DOOR_ANIMTOUNLOCK,
	L4D2_ACT_VM_ITEMPICKUP_EXTEND,
	L4D2_ACT_VM_ITEMPICKUP_EXTEND_LAYER,
	L4D2_ACT_VM_ITEMPICKUP_LOOP,
	L4D2_ACT_VM_ITEMPICKUP_LOOP_LAYER,
	L4D2_ACT_VM_ITEMPICKUP_RETRACT,
	L4D2_ACT_VM_ITEMPICKUP_RETRACT_LAYER,
	L4D2_ACT_VM_HELPINGHAND_EXTEND,
	L4D2_ACT_VM_HELPINGHAND_EXTEND_LAYER,
	L4D2_ACT_VM_HELPINGHAND_LOOP,
	L4D2_ACT_VM_HELPINGHAND_LOOP_LAYER,
	L4D2_ACT_VM_HELPINGHAND_RETRACT,
	L4D2_ACT_VM_HELPINGHAND_RETRACT_LAYER,
	L4D2_ACT_VM_ITEMPICKUP_LOOP_PISTOL,
	L4D2_ACT_VM_ITEMPICKUP_LOOP_PISTOL_LAYER,
	L4D2_ACT_VM_ITEMPICKUP_EXTEND_PISTOL,
	L4D2_ACT_VM_ITEMPICKUP_EXTEND_PISTOL_LAYER,
	L4D2_ACT_VM_ITEMPICKUP_RETRACT_PISTOL,
	L4D2_ACT_VM_ITEMPICKUP_RETRACT_PISTOL_LAYER,
	L4D2_ACT_VM_HELPINGHAND_LOOP_PISTOL,
	L4D2_ACT_VM_HELPINGHAND_LOOP_PISTOL_LAYER,
	L4D2_ACT_VM_HELPINGHAND_EXTEND_PISTOL,
	L4D2_ACT_VM_HELPINGHAND_EXTEND_PISTOL_LAYER,
	L4D2_ACT_VM_HELPINGHAND_RETRACT_PISTOL,
	L4D2_ACT_VM_HELPINGHAND_RETRACT_PISTOL_LAYER,
	L4D2_ACT_VM_ITEMPICKUP_LOOP_DUAL_PISTOL,
	L4D2_ACT_VM_ITEMPICKUP_LOOP_DUAL_PISTOL_LAYER,
	L4D2_ACT_VM_ITEMPICKUP_EXTEND_DUAL_PISTOL,
	L4D2_ACT_VM_ITEMPICKUP_EXTEND_DUAL_PISTOL_LAYER,
	L4D2_ACT_VM_ITEMPICKUP_RETRACT_DUAL_PISTOL,
	L4D2_ACT_VM_ITEMPICKUP_RETRACT_DUAL_PISTOL_LAYER,
	L4D2_ACT_VM_HELPINGHAND_LOOP_DUAL_PISTOL,
	L4D2_ACT_VM_HELPINGHAND_LOOP_DUAL_PISTOL_LAYER,
	L4D2_ACT_VM_HELPINGHAND_EXTEND_DUAL_PISTOL,
	L4D2_ACT_VM_HELPINGHAND_EXTEND_DUAL_PISTOL_LAYER,
	L4D2_ACT_VM_HELPINGHAND_RETRACT_DUAL_PISTOL,
	L4D2_ACT_VM_HELPINGHAND_RETRACT_DUAL_PISTOL_LAYER,
	L4D2_ACT_VM_ITEMPICKUP_LOOP_RIFLE,
	L4D2_ACT_VM_ITEMPICKUP_LOOP_RIFLE_LAYER,
	L4D2_ACT_VM_ITEMPICKUP_EXTEND_RIFLE,
	L4D2_ACT_VM_ITEMPICKUP_EXTEND_RIFLE_LAYER,
	L4D2_ACT_VM_ITEMPICKUP_RETRACT_RIFLE,
	L4D2_ACT_VM_ITEMPICKUP_RETRACT_RIFLE_LAYER,
	L4D2_ACT_VM_HELPINGHAND_LOOP_RIFLE,
	L4D2_ACT_VM_HELPINGHAND_LOOP_RIFLE_LAYER,
	L4D2_ACT_VM_HELPINGHAND_EXTEND_RIFLE,
	L4D2_ACT_VM_HELPINGHAND_EXTEND_RIFLE_LAYER,
	L4D2_ACT_VM_HELPINGHAND_RETRACT_RIFLE,
	L4D2_ACT_VM_HELPINGHAND_RETRACT_RIFLE_LAYER,
	L4D2_ACT_VM_ITEMPICKUP_LOOP_SMG,
	L4D2_ACT_VM_ITEMPICKUP_LOOP_SMG_LAYER,
	L4D2_ACT_VM_ITEMPICKUP_EXTEND_SMG,
	L4D2_ACT_VM_ITEMPICKUP_EXTEND_SMG_LAYER,
	L4D2_ACT_VM_ITEMPICKUP_RETRACT_SMG,
	L4D2_ACT_VM_ITEMPICKUP_RETRACT_SMG_LAYER,
	L4D2_ACT_VM_HELPINGHAND_LOOP_SMG,
	L4D2_ACT_VM_HELPINGHAND_LOOP_SMG_LAYER,
	L4D2_ACT_VM_HELPINGHAND_EXTEND_SMG,
	L4D2_ACT_VM_HELPINGHAND_EXTEND_SMG_LAYER,
	L4D2_ACT_VM_HELPINGHAND_RETRACT_SMG,
	L4D2_ACT_VM_HELPINGHAND_RETRACT_SMG_LAYER,
	L4D2_ACT_VM_ITEMPICKUP_LOOP_SNIPER,
	L4D2_ACT_VM_ITEMPICKUP_LOOP_SNIPER_LAYER,
	L4D2_ACT_VM_ITEMPICKUP_EXTEND_SNIPER,
	L4D2_ACT_VM_ITEMPICKUP_EXTEND_SNIPER_LAYER,
	L4D2_ACT_VM_ITEMPICKUP_RETRACT_SNIPER,
	L4D2_ACT_VM_ITEMPICKUP_RETRACT_SNIPER_LAYER,
	L4D2_ACT_VM_HELPINGHAND_LOOP_SNIPER,
	L4D2_ACT_VM_HELPINGHAND_LOOP_SNIPER_LAYER,
	L4D2_ACT_VM_HELPINGHAND_EXTEND_SNIPER,
	L4D2_ACT_VM_HELPINGHAND_EXTEND_SNIPER_LAYER,
	L4D2_ACT_VM_HELPINGHAND_RETRACT_SNIPER,
	L4D2_ACT_VM_HELPINGHAND_RETRACT_SNIPER_LAYER,
	L4D2_ACT_VM_ITEMPICKUP_LOOP_PIPEBOMB,
	L4D2_ACT_VM_ITEMPICKUP_LOOP_PIPEBOMB_LAYER,
	L4D2_ACT_VM_ITEMPICKUP_EXTEND_PIPEBOMB,
	L4D2_ACT_VM_ITEMPICKUP_EXTEND_PIPEBOMB_LAYER,
	L4D2_ACT_VM_ITEMPICKUP_RETRACT_PIPEBOMB,
	L4D2_ACT_VM_ITEMPICKUP_RETRACT_PIPEBOMB_LAYER,
	L4D2_ACT_VM_HELPINGHAND_LOOP_PIPEBOMB,
	L4D2_ACT_VM_HELPINGHAND_LOOP_PIPEBOMB_LAYER,
	L4D2_ACT_VM_HELPINGHAND_EXTEND_PIPEBOMB,
	L4D2_ACT_VM_HELPINGHAND_EXTEND_PIPEBOMB_LAYER,
	L4D2_ACT_VM_HELPINGHAND_RETRACT_PIPEBOMB,
	L4D2_ACT_VM_HELPINGHAND_RETRACT_PIPEBOMB_LAYER,
	L4D2_ACT_VM_ITEMPICKUP_LOOP_MOLOTOV,
	L4D2_ACT_VM_ITEMPICKUP_LOOP_MOLOTOV_LAYER,
	L4D2_ACT_VM_ITEMPICKUP_EXTEND_MOLOTOV,
	L4D2_ACT_VM_ITEMPICKUP_EXTEND_MOLOTOV_LAYER,
	L4D2_ACT_VM_ITEMPICKUP_RETRACT_MOLOTOV,
	L4D2_ACT_VM_ITEMPICKUP_RETRACT_MOLOTOV_LAYER,
	L4D2_ACT_VM_HELPINGHAND_LOOP_MOLOTOV,
	L4D2_ACT_VM_HELPINGHAND_LOOP_MOLOTOV_LAYER,
	L4D2_ACT_VM_HELPINGHAND_EXTEND_MOLOTOV,
	L4D2_ACT_VM_HELPINGHAND_EXTEND_MOLOTOV_LAYER,
	L4D2_ACT_VM_HELPINGHAND_RETRACT_MOLOTOV,
	L4D2_ACT_VM_HELPINGHAND_RETRACT_MOLOTOV_LAYER,
	L4D2_ACT_VM_ITEMPICKUP_LOOP_MEDKIT,
	L4D2_ACT_VM_ITEMPICKUP_LOOP_MEDKIT_LAYER,
	L4D2_ACT_VM_ITEMPICKUP_EXTEND_MEDKIT,
	L4D2_ACT_VM_ITEMPICKUP_EXTEND_MEDKIT_LAYER,
	L4D2_ACT_VM_ITEMPICKUP_RETRACT_MEDKIT,
	L4D2_ACT_VM_ITEMPICKUP_RETRACT_MEDKIT_LAYER,
	L4D2_ACT_VM_HELPINGHAND_LOOP_MEDKIT,
	L4D2_ACT_VM_HELPINGHAND_LOOP_MEDKIT_LAYER,
	L4D2_ACT_VM_HELPINGHAND_EXTEND_MEDKIT,
	L4D2_ACT_VM_HELPINGHAND_EXTEND_MEDKIT_LAYER,
	L4D2_ACT_VM_HELPINGHAND_RETRACT_MEDKIT,
	L4D2_ACT_VM_HELPINGHAND_RETRACT_MEDKIT_LAYER,
	L4D2_ACT_VM_ITEMPICKUP_LOOP_PAINPILLS,
	L4D2_ACT_VM_ITEMPICKUP_LOOP_PAINPILLS_LAYER,
	L4D2_ACT_VM_ITEMPICKUP_EXTEND_PAINPILLS,
	L4D2_ACT_VM_ITEMPICKUP_EXTEND_PAINPILLS_LAYER,
	L4D2_ACT_VM_ITEMPICKUP_RETRACT_PAINPILLS,
	L4D2_ACT_VM_ITEMPICKUP_RETRACT_PAINPILLS_LAYER,
	L4D2_ACT_VM_HELPINGHAND_LOOP_PAINPILLS,
	L4D2_ACT_VM_HELPINGHAND_LOOP_PAINPILLS_LAYER,
	L4D2_ACT_VM_HELPINGHAND_EXTEND_PAINPILLS,
	L4D2_ACT_VM_HELPINGHAND_EXTEND_PAINPILLS_LAYER,
	L4D2_ACT_VM_HELPINGHAND_RETRACT_PAINPILLS,
	L4D2_ACT_VM_HELPINGHAND_RETRACT_PAINPILLS_LAYER,
	L4D2_ACT_VM_CANCEL,
	L4D2_ACT_VM_CANCEL_LAYER,
	L4D2_ACT_CROUCHIDLE_RIFLE,
	L4D2_ACT_IDLE_INJURED_RIFLE,
	L4D2_ACT_WALK_INJURED_RIFLE,
	L4D2_ACT_RUN_INJURED_RIFLE,
	L4D2_ACT_DEPLOY_RIFLE,
	L4D2_ACT_PRIMARYATTACK_RIFLE,
	L4D2_ACT_RELOAD_RIFLE,
	L4D2_ACT_IDLE_CALM_RIFLE,
	L4D2_ACT_WALK_CALM_RIFLE,
	L4D2_ACT_RUN_CALM_RIFLE,
	L4D2_ACT_MELEE_SWEEP_RIFLE_IDLE,
	L4D2_ACT_MELEE_SHOVE_RIFLE_IDLE,
	L4D2_ACT_MELEE_STRAIGHT_RIFLE_IDLE,
	L4D2_ACT_MELEE_SWEEP_RIFLE_RUN,
	L4D2_ACT_MELEE_SHOVE_RIFLE_RUN,
	L4D2_ACT_MELEE_STRAIGHT_RIFLE_RUN,
	L4D2_ACT_TERROR_PULLED_RUN_RIFLE,
	L4D2_ACT_MELEE_STOMP_RIFLE_IDLE,
	L4D2_ACT_MELEE_STOMP_RIFLE_WALK,
	L4D2_ACT_IDLE_SHOTGUN,
	L4D2_ACT_WALK_SHOTGUN,
	L4D2_ACT_RUN_SHOTGUN,
	L4D2_ACT_IDLE_CALM_SHOTGUN,
	L4D2_ACT_CROUCHIDLE_SHOTGUN,
	L4D2_ACT_RUN_CROUCH_SHOTGUN,
	L4D2_ACT_DEPLOY_SHOTGUN,
	L4D2_ACT_PRIMARYATTACK_SHOTGUN,
	L4D2_ACT_RELOAD_SHOTGUN_START,
	L4D2_ACT_RELOAD_SHOTGUN_LOOP,
	L4D2_ACT_RELOAD_SHOTGUN_END,
	L4D2_ACT_IDLE_PUMPSHOTGUN,
	L4D2_ACT_CROUCHIDLE_PUMPSHOTGUN,
	L4D2_ACT_IDLE_CALM_PUMPSHOTGUN,
	L4D2_ACT_IDLE_INJURED_PUMPSHOTGUN,
	L4D2_ACT_WALK_PUMPSHOTGUN,
	L4D2_ACT_RUN_CROUCH_PUMPSHOTGUN,
	L4D2_ACT_RUN_PUMPSHOTGUN,
	L4D2_ACT_WALK_CALM_PUMPSHOTGUN,
	L4D2_ACT_RUN_CALM_PUMPSHOTGUN,
	L4D2_ACT_WALK_INJURED_PUMPSHOTGUN,
	L4D2_ACT_RUN_INJURED_PUMPSHOTGUN,
	L4D2_ACT_PRIMARYATTACK_PUMPSHOTGUN,
	L4D2_ACT_RELOAD_PUMPSHOTGUN_START,
	L4D2_ACT_RELOAD_PUMPSHOTGUN_LOOP,
	L4D2_ACT_RELOAD_PUMPSHOTGUN_END,
	L4D2_ACT_RELOAD_GRENADE_LAUNCHER,
	L4D2_ACT_IDLE_GREN,
	L4D2_ACT_CROUCHIDLE_GREN,
	L4D2_ACT_IDLE_INJURED_GREN,
	L4D2_ACT_RUN_GREN,
	L4D2_ACT_WALK_GREN,
	L4D2_ACT_RUN_CROUCH_GREN,
	L4D2_ACT_DEPLOY_GREN,
	L4D2_ACT_WALK_INJURED_GREN,
	L4D2_ACT_RUN_INJURED_GREN,
	L4D2_ACT_PRIMARYATTACK_GREN1_IDLE,
	L4D2_ACT_PRIMARYATTACK_GREN2_IDLE,
	L4D2_ACT_PRIMARYATTACK_GREN1_RUN,
	L4D2_ACT_PRIMARYATTACK_GREN2_RUN,
	L4D2_ACT_IDLE_GREN_PULL_BACK,
	L4D2_ACT_CROUCHIDLE_GREN_PULL_BACK,
	L4D2_ACT_IDLE_INJURED_GREN_PULL_BACK,
	L4D2_ACT_RUN_GREN_PULL_BACK,
	L4D2_ACT_WALK_GREN_PULL_BACK,
	L4D2_ACT_RUN_CROUCH_GREN_PULL_BACK,
	L4D2_ACT_WALK_INJURED_GREN_PULL_BACK,
	L4D2_ACT_RUN_INJURED_GREN_PULL_BACK,
	L4D2_ACT_IDLE_SNIPER,
	L4D2_ACT_CROUCHIDLE_SNIPER,
	L4D2_ACT_IDLE_CALM_SNIPER,
	L4D2_ACT_IDLE_INJURED_SNIPER,
	L4D2_ACT_WALK_SNIPER,
	L4D2_ACT_RUN_CROUCH_SNIPER,
	L4D2_ACT_RUN_SNIPER,
	L4D2_ACT_WALK_CALM_SNIPER,
	L4D2_ACT_RUN_CALM_SNIPER,
	L4D2_ACT_WALK_INJURED_SNIPER,
	L4D2_ACT_RUN_INJURED_SNIPER,
	L4D2_ACT_IDLE_SNIPER_ZOOMED,
	L4D2_ACT_CROUCHIDLE_SNIPER_ZOOMED,
	L4D2_ACT_IDLE_INJURED_SNIPER_ZOOMED,
	L4D2_ACT_IDLE_SNIPER_MILITARY,
	L4D2_ACT_IDLE_SNIPER_MILITARYZOOMED,
	L4D2_ACT_CROUCHIDLE_SNIPER_MILITARY,
	L4D2_ACT_CROUCHIDLE_SNIPER_MILITARYZOOMED,
	L4D2_ACT_IDLE_CALM_SNIPER_MILITARY,
	L4D2_ACT_IDLE_INJURED_SNIPER_MILITARY,
	L4D2_ACT_IDLE_INJURED_SNIPER_MILITARYZOOMED,
	L4D2_ACT_RUN_CROUCH_SNIPER_MILITARY,
	L4D2_ACT_WALK_SNIPER_MILITARY,
	L4D2_ACT_RUN_SNIPER_MILITARY,
	L4D2_ACT_WALK_CALM_SNIPER_MILITARY,
	L4D2_ACT_RUN_CALM_SNIPER_MILITARY,
	L4D2_ACT_WALK_INJURED_SNIPER_MILITARY,
	L4D2_ACT_RUN_INJURED_SNIPER_MILITARY,
	L4D2_ACT_IDLE_SMG,
	L4D2_ACT_WALK_SMG,
	L4D2_ACT_RUN_SMG,
	L4D2_ACT_CROUCHIDLE_SMG,
	L4D2_ACT_RUN_CROUCH_SMG,
	L4D2_ACT_IDLE_INJURED_SMG,
	L4D2_ACT_WALK_INJURED_SMG,
	L4D2_ACT_RUN_INJURED_SMG,
	L4D2_ACT_IDLE_CALM_SMG,
	L4D2_ACT_WALK_CALM_SMG,
	L4D2_ACT_RUN_CALM_SMG,
	L4D2_ACT_PRIMARYATTACK_SMG,
	L4D2_ACT_RELOAD_SMG,
	L4D2_ACT_IDLE_FIRSTAIDKIT,
	L4D2_ACT_CROUCHIDLE_FIRSTAIDKIT,
	L4D2_ACT_IDLE_INJURED_FIRSTAIDKIT,
	L4D2_ACT_RUN_FIRSTAIDKIT,
	L4D2_ACT_WALK_FIRSTAIDKIT,
	L4D2_ACT_RUN_CROUCH_FIRSTAIDKIT,
	L4D2_ACT_WALK_INJURED_FIRSTAIDKIT,
	L4D2_ACT_RUN_INJURED_FIRSTAIDKIT,
	L4D2_ACT_MELEE_SWEEP_FIRSTAIDKIT,
	L4D2_ACT_MELEE_SWEEP_COLA,
	L4D2_ACT_MELEE_SWEEP_DEFIBRILLATOR,
	L4D2_ACT_MELEE_SWEEP_UPGRADE_PACK,
	L4D2_ACT_CROUCHIDLE_PISTOL,
	L4D2_ACT_RUN_CROUCH_PISTOL,
	L4D2_ACT_IDLE_INJURED_PISTOL,
	L4D2_ACT_WALK_INJURED_PISTOL,
	L4D2_ACT_RUN_INJURED_PISTOL,
	L4D2_ACT_DEPLOY_PISTOL,
	L4D2_ACT_PRIMARYATTACK_PISTOL,
	L4D2_ACT_IDLE_CALM_PISTOL,
	L4D2_ACT_WALK_CALM_PISTOL,
	L4D2_ACT_RUN_CALM_PISTOL,
	L4D2_ACT_IDLE_ELITES,
	L4D2_ACT_WALK_ELITES,
	L4D2_ACT_RUN_ELITES,
	L4D2_ACT_CROUCHIDLE_ELITES,
	L4D2_ACT_RUN_CROUCH_ELITES,
	L4D2_ACT_IDLE_INJURED_ELITES,
	L4D2_ACT_WALK_INJURED_ELITES,
	L4D2_ACT_RUN_INJURED_ELITES,
	L4D2_ACT_DEPLOY_ELITES,
	L4D2_ACT_PRIMARYATTACK_ELITES_R,
	L4D2_ACT_PRIMARYATTACK_ELITES_L,
	L4D2_ACT_IDLE_CALM_ELITES,
	L4D2_ACT_WALK_CALM_ELITES,
	L4D2_ACT_RUN_CALM_ELITES,
	L4D2_ACT_RELOAD_ELITES,
	L4D2_ACT_RELOAD_M4,
	L4D2_ACT_PRIMARYATTACK_XM1014,
	L4D2_ACT_PRIMARYATTACK_M3S90,
	L4D2_ACT_IDLE_GASCAN,
	L4D2_ACT_CROUCHIDLE_GASCAN,
	L4D2_ACT_IDLE_CALM_GASCAN,
	L4D2_ACT_IDLE_INJURED_GASCAN,
	L4D2_ACT_RUN_GASCAN,
	L4D2_ACT_WALK_GASCAN,
	L4D2_ACT_RUN_CROUCH_GASCAN,
	L4D2_ACT_RUN_INJURED_GASCAN,
	L4D2_ACT_JUMP_GASCAN,
	L4D2_ACT_MELEE_SWEEP_GASCAN,
	L4D2_ACT_IDLE_O2,
	L4D2_ACT_CROUCHIDLE_O2,
	L4D2_ACT_IDLE_CALM_O2,
	L4D2_ACT_IDLE_INJURED_O2,
	L4D2_ACT_RUN_O2,
	L4D2_ACT_WALK_O2,
	L4D2_ACT_RUN_CROUCH_O2,
	L4D2_ACT_RUN_INJURED_O2,
	L4D2_ACT_JUMP_O2,
	L4D2_ACT_MELEE_SWEEP_O2,
	L4D2_ACT_IDLE_GNOME,
	L4D2_ACT_CROUCHIDLE_GNOME,
	L4D2_ACT_IDLE_CALM_GNOME,
	L4D2_ACT_IDLE_INJURED_GNOME,
	L4D2_ACT_RUN_CROUCH_GNOME,
	L4D2_ACT_WALK_GNOME,
	L4D2_ACT_RUN_GNOME,
	L4D2_ACT_WALK_CALM_GNOME,
	L4D2_ACT_RUN_CALM_GNOME,
	L4D2_ACT_WALK_INJURED_GNOME,
	L4D2_ACT_RUN_INJURED_GNOME,
	L4D2_ACT_JUMP_GNOME,
	L4D2_ACT_MELEE_SWEEP_GNOME,
	L4D2_ACT_SHOOT_E2W_AXE,
	L4D2_ACT_SHOOT_E2W_IDLE_AXE,
	L4D2_ACT_SHOOT_W2E_AXE,
	L4D2_ACT_SHOOT_W2E_IDLE_AXE,
	L4D2_ACT_SHOOT_N2S_AXE,
	L4D2_ACT_SHOOT_N2S_IDLE_AXE,
	L4D2_ACT_SHOOT_S2N_AXE,
	L4D2_ACT_SHOOT_S2N_IDLE_AXE,
	L4D2_ACT_SHOOT_STRONG_AXE,
	L4D2_ACT_SHOOT_STRONG_IDLE_AXE,
	L4D2_ACT_SHOOT_SECONDARY_AXE,
	L4D2_ACT_SHOOT_SECONDARY_IDLE_AXE,
	L4D2_ACT_IDLE_AXE,
	L4D2_ACT_CROUCHIDLE_AXE,
	L4D2_ACT_IDLE_CALM_AXE,
	L4D2_ACT_IDLE_INJURED_AXE,
	L4D2_ACT_RUN_AXE,
	L4D2_ACT_WALK_AXE,
	L4D2_ACT_WALK_INJURED_AXE,
	L4D2_ACT_RUN_CROUCH_AXE,
	L4D2_ACT_RUN_INJURED_AXE,
	L4D2_ACT_JUMP_AXE,
	L4D2_ACT_SHOOT_E2W_BAT,
	L4D2_ACT_SHOOT_E2W_IDLE_BAT,
	L4D2_ACT_SHOOT_W2E_BAT,
	L4D2_ACT_SHOOT_W2E_IDLE_BAT,
	L4D2_ACT_SHOOT_N2S_BAT,
	L4D2_ACT_SHOOT_N2S_IDLE_BAT,
	L4D2_ACT_SHOOT_S2N_BAT,
	L4D2_ACT_SHOOT_S2N_IDLE_BAT,
	L4D2_ACT_SHOOT_STRONG_BAT,
	L4D2_ACT_SHOOT_STRONG_IDLE_BAT,
	L4D2_ACT_SHOOT_SECONDARY_BAT,
	L4D2_ACT_SHOOT_SECONDARY_IDLE_BAT,
	L4D2_ACT_IDLE_BAT,
	L4D2_ACT_CROUCHIDLE_BAT,
	L4D2_ACT_IDLE_CALM_BAT,
	L4D2_ACT_IDLE_INJURED_BAT,
	L4D2_ACT_RUN_BAT,
	L4D2_ACT_WALK_BAT,
	L4D2_ACT_WALK_INJURED_BAT,
	L4D2_ACT_RUN_CROUCH_BAT,
	L4D2_ACT_RUN_INJURED_BAT,
	L4D2_ACT_JUMP_BAT,
	L4D2_ACT_SHOOT_E2W_KATANA,
	L4D2_ACT_SHOOT_E2W_IDLE_KATANA,
	L4D2_ACT_SHOOT_W2E_KATANA,
	L4D2_ACT_SHOOT_W2E_IDLE_KATANA,
	L4D2_ACT_SHOOT_E2W_FRYINGPAN,
	L4D2_ACT_SHOOT_E2W_IDLE_FRYINGPAN,
	L4D2_ACT_SHOOT_W2E_FRYINGPAN,
	L4D2_ACT_SHOOT_W2E_IDLE_FRYINGPAN,
	L4D2_ACT_SHOOT_N2S_FRYINGPAN,
	L4D2_ACT_SHOOT_N2S_IDLE_FRYINGPAN,
	L4D2_ACT_SHOOT_S2N_FRYINGPAN,
	L4D2_ACT_SHOOT_S2N_IDLE_FRYINGPAN,
	L4D2_ACT_SHOOT_STRONG_FRYINGPAN,
	L4D2_ACT_SHOOT_STRONG_IDLE_FRYINGPAN,
	L4D2_ACT_SHOOT_SECONDARY_FRYINGPAN,
	L4D2_ACT_SHOOT_SECONDARY_IDLE_FRYINGPAN,
	L4D2_ACT_IDLE_FRYINGPAN,
	L4D2_ACT_CROUCHIDLE_FRYINGPAN,
	L4D2_ACT_IDLE_CALM_FRYINGPAN,
	L4D2_ACT_IDLE_INJURED_FRYINGPAN,
	L4D2_ACT_RUN_FRYINGPAN,
	L4D2_ACT_WALK_FRYINGPAN,
	L4D2_ACT_WALK_INJURED_FRYINGPAN,
	L4D2_ACT_RUN_CROUCH_FRYINGPAN,
	L4D2_ACT_RUN_INJURED_FRYINGPAN,
	L4D2_ACT_JUMP_FRYINGPAN,
	L4D2_ACT_SHOOT_E2W_GUITAR,
	L4D2_ACT_SHOOT_E2W_IDLE_GUITAR,
	L4D2_ACT_SHOOT_W2E_GUITAR,
	L4D2_ACT_SHOOT_W2E_IDLE_GUITAR,
	L4D2_ACT_SHOOT_N2S_GUITAR,
	L4D2_ACT_SHOOT_N2S_IDLE_GUITAR,
	L4D2_ACT_SHOOT_S2N_GUITAR,
	L4D2_ACT_SHOOT_S2N_IDLE_GUITAR,
	L4D2_ACT_SHOOT_STRONG_GUITAR,
	L4D2_ACT_SHOOT_STRONG_IDLE_GUITAR,
	L4D2_ACT_SHOOT_SECONDARY_GUITAR,
	L4D2_ACT_SHOOT_SECONDARY_IDLE_GUITAR,
	L4D2_ACT_IDLE_GUITAR,
	L4D2_ACT_CROUCHIDLE_GUITAR,
	L4D2_ACT_IDLE_CALM_GUITAR,
	L4D2_ACT_IDLE_INJURED_GUITAR,
	L4D2_ACT_RUN_GUITAR,
	L4D2_ACT_WALK_GUITAR,
	L4D2_ACT_WALK_INJURED_GUITAR,
	L4D2_ACT_RUN_CROUCH_GUITAR,
	L4D2_ACT_RUN_INJURED_GUITAR,
	L4D2_ACT_JUMP_GUITAR,
	L4D2_ACT_IDLE_CHAINSAW,
	L4D2_ACT_IDLE_ATTACK_CHAINSAW,
	L4D2_ACT_WALK_CHAINSAW,
	L4D2_ACT_RUN_CHAINSAW,
	L4D2_ACT_CROUCHIDLE_CHAINSAW,
	L4D2_ACT_IDLE_CALM_CHAINSAW,
	L4D2_ACT_IDLE_INJURED_CHAINSAW,
	L4D2_ACT_RUN_CALM_CHAINSAW,
	L4D2_ACT_WALK_CALM_CHAINSAW,
	L4D2_ACT_WALK_INJURED_CHAINSAW,
	L4D2_ACT_RUN_CROUCH_CHAINSAW,
	L4D2_ACT_RUN_INJURED_CHAINSAW,
	L4D2_ACT_JUMP_CHAINSAW,
	L4D2_ACT_MELEE_SWEEP_CHAINSAW,
	L4D2_ACT_PRIMARYATTACK_CHAINSAW,
	L4D2_ACT_DEPLOY_CHAINSAW,
	L4D2_ACT_TERROR_CHAINSAW_START,
	L4D2_ACT_SHOOT_W2E_CHAINSAW,
	L4D2_ACT_SHOOT_CHAINSAW,
	L4D2_ACT_CHAINSAW_STARTUP,
	L4D2_ACT_IDLE_GRENADELAUNCHER,
	L4D2_ACT_WALK_GRENADELAUNCHER,
	L4D2_ACT_RUN_GRENADELAUNCHER,
	L4D2_ACT_CROUCHIDLE_GRENADELAUNCHER,
	L4D2_ACT_IDLE_CALM_GRENADELAUNCHER,
	L4D2_ACT_IDLE_INJURED_GRENADELAUNCHER,
	L4D2_ACT_RUN_CALM_GRENADELAUNCHER,
	L4D2_ACT_WALK_CALM_GRENADELAUNCHER,
	L4D2_ACT_WALK_INJURED_GRENADELAUNCHER,
	L4D2_ACT_RUN_CROUCH_GRENADELAUNCHER,
	L4D2_ACT_RUN_INJURED_GRENADELAUNCHER,
	L4D2_ACT_JUMP_GRENADELAUNCHER,
	L4D2_ACT_MELEE_SWEEP_GRENADELAUNCHER,
	L4D2_ACT_PRIMARYATTACK_GRENADELAUNCHER,
	L4D2_ACT_DEPLOY_GRENADELAUNCHER,
	L4D2_ACT_VM_MELEE,
	L4D2_ACT_VM_SHOOT_LAYER,
	L4D2_ACT_VM_PRIMARYATTACK_LAYER,
	L4D2_ACT_VM_SECONDARYATTACK_LAYER,
	L4D2_ACT_VM_MELEE_LAYER,
	L4D2_ACT_VM_PICKUP_LAYER,
	L4D2_ACT_VM_PICKUP_CLIPIN,
	L4D2_ACT_VM_PICKUP_CLIPIN_LAYER,
	L4D2_ACT_VM_PICKUP_CHARGING,
	L4D2_ACT_VM_PICKUP_CHARGING_LAYER,
	L4D2_ACT_VM_PICKUP_FASSIST,
	L4D2_ACT_VM_PICKUP_FASSIST_LAYER,
	L4D2_ACT_VM_RELOAD_PUMP,
	L4D2_ACT_VM_RELOAD_PUMP_LAYER,
	L4D2_ACT_VM_RELOAD_LAYER,
	L4D2_ACT_VM_RELOAD_CLIPOUT,
	L4D2_ACT_VM_RELOAD_CLIPOUT_LAYER,
	L4D2_ACT_VM_RELOAD_CLIPIN,
	L4D2_ACT_VM_RELOAD_CLIPIN_LAYER,
	L4D2_ACT_VM_RELOAD_EMPTY_LAYER,
	L4D2_ACT_VM_RELOAD_EMPTY_CLIPOUT,
	L4D2_ACT_VM_RELOAD_EMPTY_CLIPOUT_LAYER,
	L4D2_ACT_VM_RELOAD_EMPTY_CLIPIN,
	L4D2_ACT_VM_RELOAD_EMPTY_CLIPIN_LAYER,
	L4D2_ACT_VM_RELOAD_EMPTY_CLIPIN2,
	L4D2_ACT_VM_RELOAD_EMPTY_CLIPIN2_LAYER,
	L4D2_ACT_VM_DEPLOY_LAYER,
	L4D2_ACT_VM_THROW_LAYER,
	L4D2_ACT_VM_PULLPIN_LAYER,
	L4D2_ACT_VM_IDLE_BAREHAND,
	L4D2_ACT_VM_DEPLOY_BAREHAND,
	L4D2_ACT_VM_DEPLOY_BAREHAND_LAYER,
	L4D2_ACT_VM_MELEE_BAREHAND,
	L4D2_ACT_VM_MELEE_BAREHAND_LAYER,
	L4D2_ACT_VM_ITEMPICKUP_EXTEND_BAREHAND,
	L4D2_ACT_VM_ITEMPICKUP_EXTEND_BAREHAND_LAYER,
	L4D2_ACT_VM_ITEMPICKUP_LOOP_BAREHAND,
	L4D2_ACT_VM_ITEMPICKUP_LOOP_BAREHAND_LAYER,
	L4D2_ACT_VM_ITEMPICKUP_RETRACT_BAREHAND,
	L4D2_ACT_VM_ITEMPICKUP_RETRACT_BAREHAND_LAYER,
	L4D2_ACT_VM_HELPINGHAND_EXTEND_BAREHAND,
	L4D2_ACT_VM_HELPINGHAND_EXTEND_BAREHAND_LAYER,
	L4D2_ACT_VM_HELPINGHAND_LOOP_BAREHAND,
	L4D2_ACT_VM_HELPINGHAND_LOOP_BAREHAND_LAYER,
	L4D2_ACT_VM_HELPINGHAND_RETRACT_BAREHAND,
	L4D2_ACT_VM_HELPINGHAND_RETRACT_BAREHAND_LAYER,
	L4D2_ACT_VM_IDLE_DUAL_PISTOL,
	L4D2_ACT_VM_DEPLOY_DUAL_PISTOL,
	L4D2_ACT_VM_DEPLOY_DUAL_PISTOL_LAYER,
	L4D2_ACT_VM_PRIMARYATTACK_DUAL_PISTOL,
	L4D2_ACT_VM_SHOOT_DUAL_PISTOL_LAYER,
	L4D2_ACT_VM_SECONDARYATTACK_DUAL_PISTOL,
	L4D2_ACT_VM_SECONDARYATTACK_DUAL_PISTOL_LAYER,
	L4D2_ACT_VM_RELOAD_DUAL_PISTOL,
	L4D2_ACT_VM_RELOAD_DUAL_PISTOL_LAYER,
	L4D2_ACT_VM_RELOAD_CLIPOUT_DUAL_PISTOL,
	L4D2_ACT_VM_RELOAD_CLIPOUT_DUAL_PISTOL_LAYER,
	L4D2_ACT_VM_RELOAD_CLIPIN_DUAL_PISTOL,
	L4D2_ACT_VM_RELOAD_CLIPIN_DUAL_PISTOL_LAYER,
	L4D2_ACT_VM_RELOAD_EMPTY_DUAL_PISTOL,
	L4D2_ACT_VM_RELOAD_EMPTY_DUAL_PISTOL_LAYER,
	L4D2_ACT_VM_RELOAD_EMPTY_CLIPOUT_DUAL_PISTOL,
	L4D2_ACT_VM_RELOAD_EMPTY_CLIPOUT_DUAL_PISTOL_LAYER,
	L4D2_ACT_VM_RELOAD_EMPTY_CLIPIN_DUAL_PISTOL,
	L4D2_ACT_VM_RELOAD_EMPTY_CLIPIN_DUAL_PISTOL_LAYER,
	L4D2_ACT_VM_RELOAD_EMPTY_CLIPIN2_DUAL_PISTOL,
	L4D2_ACT_VM_RELOAD_EMPTY_CLIPIN2_DUAL_PISTOL_LAYER,
	L4D2_ACT_VM_PICKUP_DUAL_PISTOL,
	L4D2_ACT_VM_PICKUP_DUAL_PISTOL_LAYER,
	L4D2_ACT_VM_PICKUP_CLIPIN_DUAL_PISTOL,
	L4D2_ACT_VM_PICKUP_CLIPIN_DUAL_PISTOL_LAYER,
	L4D2_ACT_VM_PICKUP_CHARGING_DUAL_PISTOL,
	L4D2_ACT_VM_PICKUP_CHARGING_DUAL_PISTOL_LAYER,
	L4D2_ACT_VM_MELEE_DUAL_PISTOL,
	L4D2_ACT_VM_MELEE_DUAL_PISTOL_LAYER,
	L4D2_ACT_VM_IDLE_PISTOL,
	L4D2_ACT_VM_DEPLOY_PISTOL,
	L4D2_ACT_VM_DEPLOY_PISTOL_LAYER,
	L4D2_ACT_VM_PRIMARYATTACK_PISTOL,
	L4D2_ACT_VM_SHOOT_PISTOL_LAYER,
	L4D2_ACT_VM_RELOAD_PISTOL,
	L4D2_ACT_VM_RELOAD_PISTOL_LAYER,
	L4D2_ACT_VM_RELOAD_CLIPOUT_PISTOL,
	L4D2_ACT_VM_RELOAD_CLIPOUT_PISTOL_LAYER,
	L4D2_ACT_VM_RELOAD_EMPTY_PISTOL,
	L4D2_ACT_VM_RELOAD_EMPTY_PISTOL_LAYER,
	L4D2_ACT_VM_RELOAD_EMPTY_CLIPOUT_PISTOL,
	L4D2_ACT_VM_RELOAD_EMPTY_CLIPOUT_PISTOL_LAYER,
	L4D2_ACT_VM_RELOAD_EMPTY_CLIPIN_PISTOL,
	L4D2_ACT_VM_RELOAD_EMPTY_CLIPIN_PISTOL_LAYER,
	L4D2_ACT_VM_MELEE_PISTOL,
	L4D2_ACT_VM_MELEE_PISTOL_LAYER,
	L4D2_ACT_VM_IDLE_RIFLE,
	L4D2_ACT_VM_PICKUP_RIFLE,
	L4D2_ACT_VM_PICKUP_RIFLE_LAYER,
	L4D2_ACT_VM_PICKUP_CLIPIN_RIFLE,
	L4D2_ACT_VM_PICKUP_CLIPIN_RIFLE_LAYER,
	L4D2_ACT_VM_PICKUP_CHARGING_RIFLE,
	L4D2_ACT_VM_PICKUP_CHARGING_RIFLE_LAYER,
	L4D2_ACT_VM_PICKUP_FASSIST_RIFLE,
	L4D2_ACT_VM_PICKUP_FASSIST_RIFLE_LAYER,
	L4D2_ACT_VM_DEPLOY_RIFLE,
	L4D2_ACT_VM_DEPLOY_RIFLE_LAYER,
	L4D2_ACT_VM_PRIMARYATTACK_RIFLE,
	L4D2_ACT_VM_SHOOT_RIFLE_LAYER,
	L4D2_ACT_VM_RELOAD_RIFLE,
	L4D2_ACT_VM_RELOAD_RIFLE_LAYER,
	L4D2_ACT_VM_RELOAD_CLIPOUT_RIFLE,
	L4D2_ACT_VM_RELOAD_CLIPOUT_RIFLE_LAYER,
	L4D2_ACT_VM_RELOAD_EMPTY_RIFLE,
	L4D2_ACT_VM_RELOAD_EMPTY_RIFLE_LAYER,
	L4D2_ACT_VM_RELOAD_EMPTY_CLIPOUT_RIFLE,
	L4D2_ACT_VM_RELOAD_EMPTY_CLIPOUT_RIFLE_LAYER,
	L4D2_ACT_VM_RELOAD_EMPTY_CLIPIN_RIFLE,
	L4D2_ACT_VM_RELOAD_EMPTY_CLIPIN_RIFLE_LAYER,
	L4D2_ACT_VM_MELEE_RIFLE,
	L4D2_ACT_VM_MELEE_RIFLE_LAYER,
	L4D2_ACT_VM_FIDGET_RIFLE_LAYER,
	L4D2_ACT_VM_IDLE_SMG,
	L4D2_ACT_VM_PICKUP_SMG,
	L4D2_ACT_VM_PICKUP_SMG_LAYER,
	L4D2_ACT_VM_PICKUP_CLIPIN_SMG,
	L4D2_ACT_VM_PICKUP_CLIPIN_SMG_LAYER,
	L4D2_ACT_VM_PICKUP_CHARGING_SMG,
	L4D2_ACT_VM_PICKUP_CHARGING_SMG_LAYER,
	L4D2_ACT_VM_DEPLOY_SMG,
	L4D2_ACT_VM_DEPLOY_SMG_LAYER,
	L4D2_ACT_VM_PRIMARYATTACK_SMG,
	L4D2_ACT_VM_SHOOT_SMG_LAYER,
	L4D2_ACT_VM_RELOAD_SMG,
	L4D2_ACT_VM_RELOAD_SMG_LAYER,
	L4D2_ACT_VM_RELOAD_CLIPOUT_SMG,
	L4D2_ACT_VM_RELOAD_CLIPOUT_SMG_LAYER,
	L4D2_ACT_VM_RELOAD_EMPTY_SMG,
	L4D2_ACT_VM_RELOAD_EMPTY_SMG_LAYER,
	L4D2_ACT_VM_RELOAD_EMPTY_CLIPOUT_SMG,
	L4D2_ACT_VM_RELOAD_EMPTY_CLIPOUT_SMG_LAYER,
	L4D2_ACT_VM_RELOAD_EMPTY_CLIPIN_SMG,
	L4D2_ACT_VM_RELOAD_EMPTY_CLIPIN_SMG_LAYER,
	L4D2_ACT_VM_MELEE_SMG,
	L4D2_ACT_VM_MELEE_SMG_LAYER,
	L4D2_ACT_VM_FIDGET_SMG_LAYER,
	L4D2_ACT_VM_IDLE_SNIPER,
	L4D2_ACT_VM_PICKUP_SNIPER,
	L4D2_ACT_VM_PICKUP_SNIPER_LAYER,
	L4D2_ACT_VM_PICKUP_CLIPIN_SNIPER,
	L4D2_ACT_VM_PICKUP_CLIPIN_SNIPER_LAYER,
	L4D2_ACT_VM_PICKUP_CHARGING_SNIPER,
	L4D2_ACT_VM_PICKUP_CHARGING_SNIPER_LAYER,
	L4D2_ACT_VM_DEPLOY_SNIPER,
	L4D2_ACT_VM_DEPLOY_SNIPER_LAYER,
	L4D2_ACT_VM_PRIMARYATTACK_SNIPER,
	L4D2_ACT_VM_SHOOT_SNIPER_LAYER,
	L4D2_ACT_VM_RELOAD_SNIPER,
	L4D2_ACT_VM_RELOAD_SNIPER_LAYER,
	L4D2_ACT_VM_RELOAD_CLIPOUT_SNIPER,
	L4D2_ACT_VM_RELOAD_CLIPOUT_SNIPER_LAYER,
	L4D2_ACT_VM_RELOAD_EMPTY_SNIPER,
	L4D2_ACT_VM_RELOAD_EMPTY_SNIPER_LAYER,
	L4D2_ACT_VM_RELOAD_EMPTY_CLIPOUT_SNIPER,
	L4D2_ACT_VM_RELOAD_EMPTY_CLIPOUT_SNIPER_LAYER,
	L4D2_ACT_VM_RELOAD_EMPTY_CLIPIN_SNIPER,
	L4D2_ACT_VM_RELOAD_EMPTY_CLIPIN_SNIPER_LAYER,
	L4D2_ACT_VM_MELEE_SNIPER,
	L4D2_ACT_VM_MELEE_SNIPER_LAYER,
	L4D2_ACT_VM_FIDGET_SNIPER_LAYER,
	L4D2_ACT_VM_RELOAD_LOOP,
	L4D2_ACT_VM_RELOAD_LOOP_LAYER,
	L4D2_ACT_VM_RELOAD_END,
	L4D2_ACT_VM_RELOAD_END_LAYER,
	L4D2_ACT_VM_IDLE_PIPEBOMB,
	L4D2_ACT_VM_DEPLOY_PIPEBOMB,
	L4D2_ACT_VM_DEPLOY_PIPEBOMB_LAYER,
	L4D2_ACT_VM_PULLPIN_PIPEBOMB,
	L4D2_ACT_VM_PULLPIN_PIPEBOMB_LAYER,
	L4D2_ACT_VM_THROW_PIPEBOMB,
	L4D2_ACT_VM_THROW_PIPEBOMB_LAYER,
	L4D2_ACT_VM_MELEE_PIPEBOMB,
	L4D2_ACT_VM_MELEE_PIPEBOMB_LAYER,
	L4D2_ACT_VM_IDLE_MOLOTOV,
	L4D2_ACT_VM_DEPLOY_MOLOTOV,
	L4D2_ACT_VM_DEPLOY_MOLOTOV_LAYER,
	L4D2_ACT_VM_PULLPIN_MOLOTOV,
	L4D2_ACT_VM_PULLPIN_MOLOTOV_LAYER,
	L4D2_ACT_VM_THROW_MOLOTOV,
	L4D2_ACT_VM_THROW_MOLOTOV_LAYER,
	L4D2_ACT_VM_MELEE_MOLOTOV,
	L4D2_ACT_VM_MELEE_MOLOTOV_LAYER,
	L4D2_ACT_VM_IDLE_PAINPILLS,
	L4D2_ACT_VM_DEPLOY_PAINPILLS,
	L4D2_ACT_VM_DEPLOY_PAINPILLS_LAYER,
	L4D2_ACT_VM_MELEE_PAINPILLS,
	L4D2_ACT_VM_MELEE_PAINPILLS_LAYER,
	L4D2_ACT_VM_USE_PAINPILLS,
	L4D2_ACT_VM_USE_PAINPILLS_LAYER,
	L4D2_ACT_VM_IDLE_MEDKIT,
	L4D2_ACT_VM_DEPLOY_MEDKIT,
	L4D2_ACT_VM_DEPLOY_MEDKIT_LAYER,
	L4D2_ACT_VM_MELEE_MEDKIT,
	L4D2_ACT_VM_MELEE_MEDKIT_LAYER,
	L4D2_ACT_VM_IDLE_GASCAN,
	L4D2_ACT_VM_DEPLOY_GASCAN,
	L4D2_ACT_VM_PULLPIN_GASCAN,
	L4D2_ACT_VM_THROW_GASCAN,
	L4D2_ACT_VM_MELEE_GASCAN,
	L4D2_ACT_GEST_OVERHERE,
	L4D2_ACT_GEST_POINTLEFT,
	L4D2_ACT_GEST_POINTLEFT_QUICK,
	L4D2_ACT_GEST_HEAD_TWISTLEFT,
	L4D2_ACT_GEST_HEAD_DOWN,
	L4D2_ACT_GEST_GOGOGO,
	L4D2_ACT_GEST_WAVE,
	L4D2_ACT_GEST_COUGH,
	L4D2_ACT_GEST_COUGH01,
	L4D2_ACT_GEST_COUGH02,
	L4D2_ACT_GEST_COUGH03,
	L4D2_ACT_GEST_COUGH1,
	L4D2_ACT_GEST_COUGH2,
	L4D2_ACT_GEST_COUGH3,
	L4D2_ACT_GEST_VOMIT,
	L4D2_ACT_GEST_VOMIT01,
	L4D2_ACT_GEST_INTRO_CALM,
	L4D2_ACT_GEST_INTRO_WAVE,
	L4D2_ACT_DLCINTRO_01,
	L4D2_ACT_DLCINTRO_02,
	L4D2_ACT_DLCINTRO_03,
	L4D2_ACT_DLCINTRO_04,
	L4D2_ACT_DLCFI_FRANCIS_HLD,
	L4D2_ACT_DLCFI_FRANCIS_017MB,
	L4D2_ACT_DLCFI_FRANCIS_018MB,
	L4D2_ACT_DLCFI_FRANCIS_01,
	L4D2_ACT_DLCFI_FRANCIS_02,
	L4D2_ACT_DLCFI_FRANCIS_03,
	L4D2_ACT_DLCFI_FRANCIS_04,
	L4D2_ACT_DLCFI_FRANCIS_05,
	L4D2_ACT_DLCFI_FRANCIS_06,
	L4D2_ACT_DLCFI_FRANCIS_07,
	L4D2_ACT_DLCFI_FRANCIS_08,
	L4D2_ACT_DLCFI_FRANCIS_08b,
	L4D2_ACT_DLCFI_FRANCIS_09,
	L4D2_ACT_DLCFI_FRANCIS_09b,
	L4D2_ACT_DLCFI_FRANCIS_10,
	L4D2_ACT_DLCFI_FRANCIS_10b,
	L4D2_ACT_DLCFI_FRANCIS_11,
	L4D2_ACT_DLCFI_FRANCIS_11b,
	L4D2_ACT_DLCFI_FRANCIS_12AH,
	L4D2_ACT_DLCFI_FRANCIS_12mr,
	L4D2_ACT_DLCFI_FRANCIS_13mr,
	L4D2_ACT_DLCFI_FRANCIS_13AH,
	L4D2_ACT_DLCFI_FRANCIS_14AH,
	L4D2_ACT_DLCFI_FRANCIS_15AH,
	L4D2_ACT_DLCFI_FRANCIS_16AH,
	L4D2_ACT_DLCFI_FRANCIS_17AH,
	L4D2_ACT_DLCFI_FRANCIS_18AH,
	L4D2_ACT_DLCFI_FRANCIS_19AH,
	L4D2_ACT_DLCFI_FRANCIS_20AH,
	L4D2_ACT_DLCFI_FRANCIS_21AH,
	L4D2_ACT_DLCFI_FRANCIS_14mr,
	L4D2_ACT_DLCFI_FRANCIS_15mr,
	L4D2_ACT_DLCFI_FRANCIS_16mr,
	L4D2_ACT_DLCFI_FRANCIS_17mr,
	L4D2_ACT_DLCFI_FRANCIS_014MB,
	L4D2_ACT_DLCFI_FRANCIS_014MBX,
	L4D2_ACT_DLCFI_FRANCIS_13nm,
	L4D2_ACT_DLCFI_LOUIS_01,
	L4D2_ACT_DLCFI_LOUIS_02,
	L4D2_ACT_DLCFI_LOUIS_03,
	L4D2_ACT_DLCFI_LOUIS_04,
	L4D2_ACT_DLCFI_LOUIS_05,
	L4D2_ACT_DLCFI_LOUIS_06,
	L4D2_ACT_DLCFI_LOUIS_07MB,
	L4D2_ACT_DLCFI_LOUIS_08MB,
	L4D2_ACT_DLCFI_LOUIS_09MB,
	L4D2_ACT_DLCFI_LOUIS_10MB,
	L4D2_ACT_DLCFI_LOUIS_11,
	L4D2_ACT_DLCFI_LOUIS_11MB,
	L4D2_ACT_DLCFI_LOUIS_11AH,
	L4D2_ACT_DLCFI_LOUIS_12,
	L4D2_ACT_DLCFI_LOUIS_012MB,
	L4D2_ACT_DLCFI_LOUIS_012MR,
	L4D2_ACT_DLCFI_LOUIS_13,
	L4D2_ACT_DLCFI_LOUIS_013MB,
	L4D2_ACT_DLCFI_LOUIS_013MR,
	L4D2_ACT_DLCFI_LOUIS_14,
	L4D2_ACT_DLCFI_LOUIS_014MB,
	L4D2_ACT_DLCFI_LOUIS_14MR,
	L4D2_ACT_DLCFI_LOUIS_15,
	L4D2_ACT_DLCFI_LOUIS_015MB,
	L4D2_ACT_DLCFI_LOUIS_016MB,
	L4D2_ACT_DLCFI_LOUIS_16JM,
	L4D2_ACT_DLCFI_LOUIS_16AJM,
	L4D2_ACT_DLCFI_LOUIS_017MB,
	L4D2_ACT_DLCFI_ZOEY_01,
	L4D2_ACT_DLCFI_ZOEY_02,
	L4D2_ACT_DLCFI_ZOEY_03,
	L4D2_ACT_DLCFI_ZOEY_04,
	L4D2_ACT_DLCFI_ZOEY_05,
	L4D2_ACT_DLCFI_ZOEY_06,
	L4D2_ACT_DLCFI_ZOEY_07MB,
	L4D2_ACT_DLCFI_ZOEY_08MB,
	L4D2_ACT_DLCFI_ZOEY_09MB,
	L4D2_ACT_DLCFI_ZOEY_10MB,
	L4D2_ACT_DLCFI_ZOEY_11MB,
	L4D2_ACT_DLCFI_ZOEY_06AH,
	L4D2_ACT_DLCFI_ZOEY_07AH,
	L4D2_ACT_DLCFI_ZOEY_07mr,
	L4D2_ACT_DLCFI_ZOEY_12MB,
	L4D2_ACT_DLCFI_ZOEY_08mr,
	L4D2_ACT_DLCFI_ZOEY_10MR,
	L4D2_ACT_DLCINTRO_ZOEY_01,
	L4D2_ACT_DLCINTRO_ZOEY_02,
	L4D2_ACT_DLCINTRO_ZOEY_03,
	L4D2_ACT_DLCINTRO_ZOEY_04,
	L4D2_ACT_DLCINTRO_ZOEY_05,
	L4D2_ACT_DLCINTRO_ZOEY_06,
	L4D2_ACT_VM_FIZZLE,
	L4D2_ACT_MP_STAND_IDLE,
	L4D2_ACT_MP_CROUCH_IDLE,
	L4D2_ACT_MP_CROUCH_DEPLOYED_IDLE,
	L4D2_ACT_MP_CROUCH_DEPLOYED,
	L4D2_ACT_MP_DEPLOYED_IDLE,
	L4D2_ACT_MP_RUN,
	L4D2_ACT_MP_WALK,
	L4D2_ACT_MP_AIRWALK,
	L4D2_ACT_MP_CROUCHWALK,
	L4D2_ACT_MP_SPRINT,
	L4D2_ACT_MP_JUMP,
	L4D2_ACT_MP_JUMP_START,
	L4D2_ACT_MP_JUMP_FLOAT,
	L4D2_ACT_MP_JUMP_LAND,
	L4D2_ACT_MP_DOUBLEJUMP,
	L4D2_ACT_MP_SWIM,
	L4D2_ACT_MP_DEPLOYED,
	L4D2_ACT_MP_SWIM_DEPLOYED,
	L4D2_ACT_MP_VCD,
	L4D2_ACT_MP_ATTACK_STAND_PRIMARYFIRE,
	L4D2_ACT_MP_ATTACK_STAND_PRIMARYFIRE_DEPLOYED,
	L4D2_ACT_MP_ATTACK_STAND_SECONDARYFIRE,
	L4D2_ACT_MP_ATTACK_STAND_GRENADE,
	L4D2_ACT_MP_ATTACK_CROUCH_PRIMARYFIRE,
	L4D2_ACT_MP_ATTACK_CROUCH_PRIMARYFIRE_DEPLOYED,
	L4D2_ACT_MP_ATTACK_CROUCH_SECONDARYFIRE,
	L4D2_ACT_MP_ATTACK_CROUCH_GRENADE,
	L4D2_ACT_MP_ATTACK_SWIM_PRIMARYFIRE,
	L4D2_ACT_MP_ATTACK_SWIM_SECONDARYFIRE,
	L4D2_ACT_MP_ATTACK_SWIM_GRENADE,
	L4D2_ACT_MP_ATTACK_AIRWALK_PRIMARYFIRE,
	L4D2_ACT_MP_ATTACK_AIRWALK_SECONDARYFIRE,
	L4D2_ACT_MP_ATTACK_AIRWALK_GRENADE,
	L4D2_ACT_MP_RELOAD_STAND,
	L4D2_ACT_MP_RELOAD_STAND_LOOP,
	L4D2_ACT_MP_RELOAD_STAND_END,
	L4D2_ACT_MP_RELOAD_CROUCH,
	L4D2_ACT_MP_RELOAD_CROUCH_LOOP,
	L4D2_ACT_MP_RELOAD_CROUCH_END,
	L4D2_ACT_MP_RELOAD_SWIM,
	L4D2_ACT_MP_RELOAD_SWIM_LOOP,
	L4D2_ACT_MP_RELOAD_SWIM_END,
	L4D2_ACT_MP_RELOAD_AIRWALK,
	L4D2_ACT_MP_RELOAD_AIRWALK_LOOP,
	L4D2_ACT_MP_RELOAD_AIRWALK_END,
	L4D2_ACT_MP_ATTACK_STAND_PREFIRE,
	L4D2_ACT_MP_ATTACK_STAND_POSTFIRE,
	L4D2_ACT_MP_ATTACK_STAND_STARTFIRE,
	L4D2_ACT_MP_ATTACK_CROUCH_PREFIRE,
	L4D2_ACT_MP_ATTACK_CROUCH_POSTFIRE,
	L4D2_ACT_MP_ATTACK_SWIM_PREFIRE,
	L4D2_ACT_MP_ATTACK_SWIM_POSTFIRE,
	L4D2_ACT_MP_STAND_PRIMARY,
	L4D2_ACT_MP_CROUCH_PRIMARY,
	L4D2_ACT_MP_RUN_PRIMARY,
	L4D2_ACT_MP_WALK_PRIMARY,
	L4D2_ACT_MP_AIRWALK_PRIMARY,
	L4D2_ACT_MP_CROUCHWALK_PRIMARY,
	L4D2_ACT_MP_JUMP_PRIMARY,
	L4D2_ACT_MP_JUMP_START_PRIMARY,
	L4D2_ACT_MP_JUMP_FLOAT_PRIMARY,
	L4D2_ACT_MP_JUMP_LAND_PRIMARY,
	L4D2_ACT_MP_SWIM_PRIMARY,
	L4D2_ACT_MP_DEPLOYED_PRIMARY,
	L4D2_ACT_MP_SWIM_DEPLOYED_PRIMARY,
	L4D2_ACT_MP_ATTACK_STAND_PRIMARY,
	L4D2_ACT_MP_ATTACK_STAND_PRIMARY_DEPLOYED,
	L4D2_ACT_MP_ATTACK_CROUCH_PRIMARY,
	L4D2_ACT_MP_ATTACK_CROUCH_PRIMARY_DEPLOYED,
	L4D2_ACT_MP_ATTACK_SWIM_PRIMARY,
	L4D2_ACT_MP_ATTACK_AIRWALK_PRIMARY,
	L4D2_ACT_MP_RELOAD_STAND_PRIMARY,
	L4D2_ACT_MP_RELOAD_STAND_PRIMARY_LOOP,
	L4D2_ACT_MP_RELOAD_STAND_PRIMARY_END,
	L4D2_ACT_MP_RELOAD_CROUCH_PRIMARY,
	L4D2_ACT_MP_RELOAD_CROUCH_PRIMARY_LOOP,
	L4D2_ACT_MP_RELOAD_CROUCH_PRIMARY_END,
	L4D2_ACT_MP_RELOAD_SWIM_PRIMARY,
	L4D2_ACT_MP_RELOAD_SWIM_PRIMARY_LOOP,
	L4D2_ACT_MP_RELOAD_SWIM_PRIMARY_END,
	L4D2_ACT_MP_RELOAD_AIRWALK_PRIMARY,
	L4D2_ACT_MP_RELOAD_AIRWALK_PRIMARY_LOOP,
	L4D2_ACT_MP_RELOAD_AIRWALK_PRIMARY_END,
	L4D2_ACT_MP_ATTACK_STAND_GRENADE_PRIMARY,
	L4D2_ACT_MP_ATTACK_CROUCH_GRENADE_PRIMARY,
	L4D2_ACT_MP_ATTACK_SWIM_GRENADE_PRIMARY,
	L4D2_ACT_MP_ATTACK_AIRWALK_GRENADE_PRIMARY,
	L4D2_ACT_MP_STAND_SECONDARY,
	L4D2_ACT_MP_CROUCH_SECONDARY,
	L4D2_ACT_MP_RUN_SECONDARY,
	L4D2_ACT_MP_WALK_SECONDARY,
	L4D2_ACT_MP_AIRWALK_SECONDARY,
	L4D2_ACT_MP_CROUCHWALK_SECONDARY,
	L4D2_ACT_MP_JUMP_SECONDARY,
	L4D2_ACT_MP_JUMP_START_SECONDARY,
	L4D2_ACT_MP_JUMP_FLOAT_SECONDARY,
	L4D2_ACT_MP_JUMP_LAND_SECONDARY,
	L4D2_ACT_MP_SWIM_SECONDARY,
	L4D2_ACT_MP_ATTACK_STAND_SECONDARY,
	L4D2_ACT_MP_ATTACK_CROUCH_SECONDARY,
	L4D2_ACT_MP_ATTACK_SWIM_SECONDARY,
	L4D2_ACT_MP_ATTACK_AIRWALK_SECONDARY,
	L4D2_ACT_MP_RELOAD_STAND_SECONDARY,
	L4D2_ACT_MP_RELOAD_STAND_SECONDARY_LOOP,
	L4D2_ACT_MP_RELOAD_STAND_SECONDARY_END,
	L4D2_ACT_MP_RELOAD_CROUCH_SECONDARY,
	L4D2_ACT_MP_RELOAD_CROUCH_SECONDARY_LOOP,
	L4D2_ACT_MP_RELOAD_CROUCH_SECONDARY_END,
	L4D2_ACT_MP_RELOAD_SWIM_SECONDARY,
	L4D2_ACT_MP_RELOAD_SWIM_SECONDARY_LOOP,
	L4D2_ACT_MP_RELOAD_SWIM_SECONDARY_END,
	L4D2_ACT_MP_RELOAD_AIRWALK_SECONDARY,
	L4D2_ACT_MP_RELOAD_AIRWALK_SECONDARY_LOOP,
	L4D2_ACT_MP_RELOAD_AIRWALK_SECONDARY_END,
	L4D2_ACT_MP_ATTACK_STAND_GRENADE_SECONDARY,
	L4D2_ACT_MP_ATTACK_CROUCH_GRENADE_SECONDARY,
	L4D2_ACT_MP_ATTACK_SWIM_GRENADE_SECONDARY,
	L4D2_ACT_MP_ATTACK_AIRWALK_GRENADE_SECONDARY,
	L4D2_ACT_MP_STAND_MELEE,
	L4D2_ACT_MP_CROUCH_MELEE,
	L4D2_ACT_MP_RUN_MELEE,
	L4D2_ACT_MP_WALK_MELEE,
	L4D2_ACT_MP_AIRWALK_MELEE,
	L4D2_ACT_MP_CROUCHWALK_MELEE,
	L4D2_ACT_MP_JUMP_MELEE,
	L4D2_ACT_MP_JUMP_START_MELEE,
	L4D2_ACT_MP_JUMP_FLOAT_MELEE,
	L4D2_ACT_MP_JUMP_LAND_MELEE,
	L4D2_ACT_MP_SWIM_MELEE,
	L4D2_ACT_MP_ATTACK_STAND_MELEE,
	L4D2_ACT_MP_ATTACK_STAND_MELEE_SECONDARY,
	L4D2_ACT_MP_ATTACK_CROUCH_MELEE,
	L4D2_ACT_MP_ATTACK_CROUCH_MELEE_SECONDARY,
	L4D2_ACT_MP_ATTACK_SWIM_MELEE,
	L4D2_ACT_MP_ATTACK_AIRWALK_MELEE,
	L4D2_ACT_MP_ATTACK_STAND_GRENADE_MELEE,
	L4D2_ACT_MP_ATTACK_CROUCH_GRENADE_MELEE,
	L4D2_ACT_MP_ATTACK_SWIM_GRENADE_MELEE,
	L4D2_ACT_MP_ATTACK_AIRWALK_GRENADE_MELEE,
	L4D2_ACT_MP_STAND_ITEM1,
	L4D2_ACT_MP_CROUCH_ITEM1,
	L4D2_ACT_MP_RUN_ITEM1,
	L4D2_ACT_MP_WALK_ITEM1,
	L4D2_ACT_MP_AIRWALK_ITEM1,
	L4D2_ACT_MP_CROUCHWALK_ITEM1,
	L4D2_ACT_MP_JUMP_ITEM1,
	L4D2_ACT_MP_JUMP_START_ITEM1,
	L4D2_ACT_MP_JUMP_FLOAT_ITEM1,
	L4D2_ACT_MP_JUMP_LAND_ITEM1,
	L4D2_ACT_MP_SWIM_ITEM1,
	L4D2_ACT_MP_ATTACK_STAND_ITEM1,
	L4D2_ACT_MP_ATTACK_STAND_ITEM1_SECONDARY,
	L4D2_ACT_MP_ATTACK_CROUCH_ITEM1,
	L4D2_ACT_MP_ATTACK_CROUCH_ITEM1_SECONDARY,
	L4D2_ACT_MP_ATTACK_SWIM_ITEM1,
	L4D2_ACT_MP_ATTACK_AIRWALK_ITEM1,
	L4D2_ACT_MP_STAND_ITEM2,
	L4D2_ACT_MP_CROUCH_ITEM2,
	L4D2_ACT_MP_RUN_ITEM2,
	L4D2_ACT_MP_WALK_ITEM2,
	L4D2_ACT_MP_AIRWALK_ITEM2,
	L4D2_ACT_MP_CROUCHWALK_ITEM2,
	L4D2_ACT_MP_JUMP_ITEM2,
	L4D2_ACT_MP_JUMP_START_ITEM2,
	L4D2_ACT_MP_JUMP_FLOAT_ITEM2,
	L4D2_ACT_MP_JUMP_LAND_ITEM2,
	L4D2_ACT_MP_SWIM_ITEM2,
	L4D2_ACT_MP_ATTACK_STAND_ITEM2,
	L4D2_ACT_MP_ATTACK_STAND_ITEM2_SECONDARY,
	L4D2_ACT_MP_ATTACK_CROUCH_ITEM2,
	L4D2_ACT_MP_ATTACK_CROUCH_ITEM2_SECONDARY,
	L4D2_ACT_MP_ATTACK_SWIM_ITEM2,
	L4D2_ACT_MP_ATTACK_AIRWALK_ITEM2,
	L4D2_ACT_MP_GESTURE_FLINCH,
	L4D2_ACT_MP_GESTURE_FLINCH_PRIMARY,
	L4D2_ACT_MP_GESTURE_FLINCH_SECONDARY,
	L4D2_ACT_MP_GESTURE_FLINCH_MELEE,
	L4D2_ACT_MP_GESTURE_FLINCH_ITEM1,
	L4D2_ACT_MP_GESTURE_FLINCH_ITEM2,
	L4D2_ACT_MP_GESTURE_FLINCH_HEAD,
	L4D2_ACT_MP_GESTURE_FLINCH_CHEST,
	L4D2_ACT_MP_GESTURE_FLINCH_STOMACH,
	L4D2_ACT_MP_GESTURE_FLINCH_LEFTARM,
	L4D2_ACT_MP_GESTURE_FLINCH_RIGHTARM,
	L4D2_ACT_MP_GESTURE_FLINCH_LEFTLEG,
	L4D2_ACT_MP_GESTURE_FLINCH_RIGHTLEG,
	L4D2_ACT_MP_GRENADE1_DRAW,
	L4D2_ACT_MP_GRENADE1_IDLE,
	L4D2_ACT_MP_GRENADE1_ATTACK,
	L4D2_ACT_MP_GRENADE2_DRAW,
	L4D2_ACT_MP_GRENADE2_IDLE,
	L4D2_ACT_MP_GRENADE2_ATTACK,
	L4D2_ACT_MP_PRIMARY_GRENADE1_DRAW,
	L4D2_ACT_MP_PRIMARY_GRENADE1_IDLE,
	L4D2_ACT_MP_PRIMARY_GRENADE1_ATTACK,
	L4D2_ACT_MP_PRIMARY_GRENADE2_DRAW,
	L4D2_ACT_MP_PRIMARY_GRENADE2_IDLE,
	L4D2_ACT_MP_PRIMARY_GRENADE2_ATTACK,
	L4D2_ACT_MP_SECONDARY_GRENADE1_DRAW,
	L4D2_ACT_MP_SECONDARY_GRENADE1_IDLE,
	L4D2_ACT_MP_SECONDARY_GRENADE1_ATTACK,
	L4D2_ACT_MP_SECONDARY_GRENADE2_DRAW,
	L4D2_ACT_MP_SECONDARY_GRENADE2_IDLE,
	L4D2_ACT_MP_SECONDARY_GRENADE2_ATTACK,
	L4D2_ACT_MP_MELEE_GRENADE1_DRAW,
	L4D2_ACT_MP_MELEE_GRENADE1_IDLE,
	L4D2_ACT_MP_MELEE_GRENADE1_ATTACK,
	L4D2_ACT_MP_MELEE_GRENADE2_DRAW,
	L4D2_ACT_MP_MELEE_GRENADE2_IDLE,
	L4D2_ACT_MP_MELEE_GRENADE2_ATTACK,
	L4D2_ACT_MP_ITEM1_GRENADE1_DRAW,
	L4D2_ACT_MP_ITEM1_GRENADE1_IDLE,
	L4D2_ACT_MP_ITEM1_GRENADE1_ATTACK,
	L4D2_ACT_MP_ITEM1_GRENADE2_DRAW,
	L4D2_ACT_MP_ITEM1_GRENADE2_IDLE,
	L4D2_ACT_MP_ITEM1_GRENADE2_ATTACK,
	L4D2_ACT_MP_ITEM2_GRENADE1_DRAW,
	L4D2_ACT_MP_ITEM2_GRENADE1_IDLE,
	L4D2_ACT_MP_ITEM2_GRENADE1_ATTACK,
	L4D2_ACT_MP_ITEM2_GRENADE2_DRAW,
	L4D2_ACT_MP_ITEM2_GRENADE2_IDLE,
	L4D2_ACT_MP_ITEM2_GRENADE2_ATTACK,
	L4D2_ACT_MP_STAND_BUILDING,
	L4D2_ACT_MP_CROUCH_BUILDING,
	L4D2_ACT_MP_RUN_BUILDING,
	L4D2_ACT_MP_WALK_BUILDING,
	L4D2_ACT_MP_AIRWALK_BUILDING,
	L4D2_ACT_MP_CROUCHWALK_BUILDING,
	L4D2_ACT_MP_JUMP_BUILDING,
	L4D2_ACT_MP_JUMP_START_BUILDING,
	L4D2_ACT_MP_JUMP_FLOAT_BUILDING,
	L4D2_ACT_MP_JUMP_LAND_BUILDING,
	L4D2_ACT_MP_SWIM_BUILDING,
	L4D2_ACT_MP_ATTACK_STAND_BUILDING,
	L4D2_ACT_MP_ATTACK_CROUCH_BUILDING,
	L4D2_ACT_MP_ATTACK_SWIM_BUILDING,
	L4D2_ACT_MP_ATTACK_AIRWALK_BUILDING,
	L4D2_ACT_MP_ATTACK_STAND_GRENADE_BUILDING,
	L4D2_ACT_MP_ATTACK_CROUCH_GRENADE_BUILDING,
	L4D2_ACT_MP_ATTACK_SWIM_GRENADE_BUILDING,
	L4D2_ACT_MP_ATTACK_AIRWALK_GRENADE_BUILDING,
	L4D2_ACT_MP_STAND_PDA,
	L4D2_ACT_MP_CROUCH_PDA,
	L4D2_ACT_MP_RUN_PDA,
	L4D2_ACT_MP_WALK_PDA,
	L4D2_ACT_MP_AIRWALK_PDA,
	L4D2_ACT_MP_CROUCHWALK_PDA,
	L4D2_ACT_MP_JUMP_PDA,
	L4D2_ACT_MP_JUMP_START_PDA,
	L4D2_ACT_MP_JUMP_FLOAT_PDA,
	L4D2_ACT_MP_JUMP_LAND_PDA,
	L4D2_ACT_MP_SWIM_PDA,
	L4D2_ACT_MP_ATTACK_STAND_PDA,
	L4D2_ACT_MP_ATTACK_SWIM_PDA,
	L4D2_ACT_MP_GESTURE_VC_HANDMOUTH,
	L4D2_ACT_MP_GESTURE_VC_FINGERPOINT,
	L4D2_ACT_MP_GESTURE_VC_FISTPUMP,
	L4D2_ACT_MP_GESTURE_VC_THUMBSUP,
	L4D2_ACT_MP_GESTURE_VC_NODYES,
	L4D2_ACT_MP_GESTURE_VC_NODNO,
	L4D2_ACT_MP_GESTURE_VC_HANDMOUTH_PRIMARY,
	L4D2_ACT_MP_GESTURE_VC_FINGERPOINT_PRIMARY,
	L4D2_ACT_MP_GESTURE_VC_FISTPUMP_PRIMARY,
	L4D2_ACT_MP_GESTURE_VC_THUMBSUP_PRIMARY,
	L4D2_ACT_MP_GESTURE_VC_NODYES_PRIMARY,
	L4D2_ACT_MP_GESTURE_VC_NODNO_PRIMARY,
	L4D2_ACT_MP_GESTURE_VC_HANDMOUTH_SECONDARY,
	L4D2_ACT_MP_GESTURE_VC_FINGERPOINT_SECONDARY,
	L4D2_ACT_MP_GESTURE_VC_FISTPUMP_SECONDARY,
	L4D2_ACT_MP_GESTURE_VC_THUMBSUP_SECONDARY,
	L4D2_ACT_MP_GESTURE_VC_NODYES_SECONDARY,
	L4D2_ACT_MP_GESTURE_VC_NODNO_SECONDARY,
	L4D2_ACT_MP_GESTURE_VC_HANDMOUTH_MELEE,
	L4D2_ACT_MP_GESTURE_VC_FINGERPOINT_MELEE,
	L4D2_ACT_MP_GESTURE_VC_FISTPUMP_MELEE,
	L4D2_ACT_MP_GESTURE_VC_THUMBSUP_MELEE,
	L4D2_ACT_MP_GESTURE_VC_NODYES_MELEE,
	L4D2_ACT_MP_GESTURE_VC_NODNO_MELEE,
	L4D2_ACT_MP_GESTURE_VC_HANDMOUTH_ITEM1,
	L4D2_ACT_MP_GESTURE_VC_FINGERPOINT_ITEM1,
	L4D2_ACT_MP_GESTURE_VC_FISTPUMP_ITEM1,
	L4D2_ACT_MP_GESTURE_VC_THUMBSUP_ITEM1,
	L4D2_ACT_MP_GESTURE_VC_NODYES_ITEM1,
	L4D2_ACT_MP_GESTURE_VC_NODNO_ITEM1,
	L4D2_ACT_MP_GESTURE_VC_HANDMOUTH_ITEM2,
	L4D2_ACT_MP_GESTURE_VC_FINGERPOINT_ITEM2,
	L4D2_ACT_MP_GESTURE_VC_FISTPUMP_ITEM2,
	L4D2_ACT_MP_GESTURE_VC_THUMBSUP_ITEM2,
	L4D2_ACT_MP_GESTURE_VC_NODYES_ITEM2,
	L4D2_ACT_MP_GESTURE_VC_NODNO_ITEM2,
	L4D2_ACT_MP_GESTURE_VC_HANDMOUTH_BUILDING,
	L4D2_ACT_MP_GESTURE_VC_FINGERPOINT_BUILDING,
	L4D2_ACT_MP_GESTURE_VC_FISTPUMP_BUILDING,
	L4D2_ACT_MP_GESTURE_VC_THUMBSUP_BUILDING,
	L4D2_ACT_MP_GESTURE_VC_NODYES_BUILDING,
	L4D2_ACT_MP_GESTURE_VC_NODNO_BUILDING,
	L4D2_ACT_MP_GESTURE_VC_HANDMOUTH_PDA,
	L4D2_ACT_MP_GESTURE_VC_FINGERPOINT_PDA,
	L4D2_ACT_MP_GESTURE_VC_FISTPUMP_PDA,
	L4D2_ACT_MP_GESTURE_VC_THUMBSUP_PDA,
	L4D2_ACT_MP_GESTURE_VC_NODYES_PDA,
	L4D2_ACT_MP_GESTURE_VC_NODNO_PDA,
	L4D2_ACT_VM_UNUSABLE,
	L4D2_ACT_VM_UNUSABLE_TO_USABLE,
	L4D2_ACT_VM_USABLE_TO_UNUSABLE,
	L4D2_ACT_PRIMARY_VM_DRAW,
	L4D2_ACT_PRIMARY_VM_HOLSTER,
	L4D2_ACT_PRIMARY_VM_IDLE,
	L4D2_ACT_PRIMARY_VM_PULLBACK,
	L4D2_ACT_PRIMARY_VM_PRIMARYATTACK,
	L4D2_ACT_PRIMARY_VM_SECONDARYATTACK,
	L4D2_ACT_PRIMARY_VM_RELOAD,
	L4D2_ACT_PRIMARY_VM_DRYFIRE,
	L4D2_ACT_PRIMARY_VM_IDLE_TO_LOWERED,
	L4D2_ACT_PRIMARY_VM_IDLE_LOWERED,
	L4D2_ACT_PRIMARY_VM_LOWERED_TO_IDLE,
	L4D2_ACT_SECONDARY_VM_DRAW,
	L4D2_ACT_SECONDARY_VM_HOLSTER,
	L4D2_ACT_SECONDARY_VM_IDLE,
	L4D2_ACT_SECONDARY_VM_PULLBACK,
	L4D2_ACT_SECONDARY_VM_PRIMARYATTACK,
	L4D2_ACT_SECONDARY_VM_SECONDARYATTACK,
	L4D2_ACT_SECONDARY_VM_RELOAD,
	L4D2_ACT_SECONDARY_VM_DRYFIRE,
	L4D2_ACT_SECONDARY_VM_IDLE_TO_LOWERED,
	L4D2_ACT_SECONDARY_VM_IDLE_LOWERED,
	L4D2_ACT_SECONDARY_VM_LOWERED_TO_IDLE,
	L4D2_ACT_MELEE_VM_DRAW,
	L4D2_ACT_MELEE_VM_HOLSTER,
	L4D2_ACT_MELEE_VM_IDLE,
	L4D2_ACT_MELEE_VM_PULLBACK,
	L4D2_ACT_MELEE_VM_PRIMARYATTACK,
	L4D2_ACT_MELEE_VM_SECONDARYATTACK,
	L4D2_ACT_MELEE_VM_RELOAD,
	L4D2_ACT_MELEE_VM_DRYFIRE,
	L4D2_ACT_MELEE_VM_IDLE_TO_LOWERED,
	L4D2_ACT_MELEE_VM_IDLE_LOWERED,
	L4D2_ACT_MELEE_VM_LOWERED_TO_IDLE,
	L4D2_ACT_PDA_VM_DRAW,
	L4D2_ACT_PDA_VM_HOLSTER,
	L4D2_ACT_PDA_VM_IDLE,
	L4D2_ACT_PDA_VM_PULLBACK,
	L4D2_ACT_PDA_VM_PRIMARYATTACK,
	L4D2_ACT_PDA_VM_SECONDARYATTACK,
	L4D2_ACT_PDA_VM_RELOAD,
	L4D2_ACT_PDA_VM_DRYFIRE,
	L4D2_ACT_PDA_VM_IDLE_TO_LOWERED,
	L4D2_ACT_PDA_VM_IDLE_LOWERED,
	L4D2_ACT_PDA_VM_LOWERED_TO_IDLE,
	L4D2_ACT_ITEM1_VM_DRAW,
	L4D2_ACT_ITEM1_VM_HOLSTER,
	L4D2_ACT_ITEM1_VM_IDLE,
	L4D2_ACT_ITEM1_VM_PULLBACK,
	L4D2_ACT_ITEM1_VM_PRIMARYATTACK,
	L4D2_ACT_ITEM1_VM_SECONDARYATTACK,
	L4D2_ACT_ITEM1_VM_RELOAD,
	L4D2_ACT_ITEM1_VM_DRYFIRE,
	L4D2_ACT_ITEM1_VM_IDLE_TO_LOWERED,
	L4D2_ACT_ITEM1_VM_IDLE_LOWERED,
	L4D2_ACT_ITEM1_VM_LOWERED_TO_IDLE,
	L4D2_ACT_ITEM2_VM_DRAW,
	L4D2_ACT_ITEM2_VM_HOLSTER,
	L4D2_ACT_ITEM2_VM_IDLE,
	L4D2_ACT_ITEM2_VM_PULLBACK,
	L4D2_ACT_ITEM2_VM_PRIMARYATTACK,
	L4D2_ACT_ITEM2_VM_SECONDARYATTACK,
	L4D2_ACT_ITEM2_VM_RELOAD,
	L4D2_ACT_ITEM2_VM_DRYFIRE,
	L4D2_ACT_ITEM2_VM_IDLE_TO_LOWERED,
	L4D2_ACT_ITEM2_VM_IDLE_LOWERED,
	L4D2_ACT_ITEM2_VM_LOWERED_TO_IDLE
}

/* The PRE hook can utilize the "ACT_*" enum defines from the "include/left4dhooks_anim.inc" include file. */
typeset AnimHookCallback
{
	/**
	 * @brief Callback called whenever animation is invoked
	 *
	 * @param client		Client triggering
	 * @param sequence		The animation "activity" (pre-hook) or "m_nSequence" (post-hook) sequence number being used
	 *
	 * @return				Plugin_Changed to change the animation sequence, Plugin_Continue otherwise
	 */
	function Action(int client, int &sequence);
}

/**
 * @brief Add a client animation hook
 * @remarks All hooks are removed on map change
 *
 * @param client			The client to hook
 * @param callback			Callback function for your pre-hook (uses "ACT_*" activity numbers) or INVALID_FUNCTION to not use
 * @param callbackPost		Callback function for your post-hook (uses "m_nSequence" sequence numbers) or INVALID_FUNCTION to not use
 *
 * @return					True on success, false if client invalid
 */
native bool AnimHookEnable(int client, AnimHookCallback callback, AnimHookCallback callbackPost = INVALID_FUNCTION);

/**
 * @brief Remove a client animation hook
 * @remarks All hooks are removed on map change
 *
 * @param client			The client to hook
 * @param callback			Callback function for your pre-hook (uses "ACT_*" activity numbers) or INVALID_FUNCTION if not used
 * @param callbackPost		Callback function for your post-hook (uses "m_nSequence" sequence numbers) or INVALID_FUNCTION if not used
 *
 * @return					True on success, false if client not hooked
 */
native bool AnimHookDisable(int client, AnimHookCallback callback, AnimHookCallback callbackPost = INVALID_FUNCTION);

/**
 * @brief Retrieves the activity string from it's relative activity number
 * @remarks activity numbers are different from a models "m_nSequence" sequence numbers
 * @remarks The ACT_* list and values are for Survivor models and differ from other models. Use the "m_nSequence" sequence value in a post hook for Special Infected
 * @remarks The "m_nSequence" sequence values for each model can be found using Left4Dead Authoring Tools > Model Viewer
 * @remarks The PRE hook can utilize the "ACT_*" enum defines from the "include/left4dhooks_anim.inc" include file instead of using this method of converting them
 *
 * @param sequence			Activity number to retrieve from
 * @param activity			Destination string to store the activity
 * @param maxlength			Size of destination string
 *
 * @return					True on success, false on failure to find
 */
native bool AnimGetActivity(int sequence, char[] activity, int maxlength);

/**
 * @brief Retrieves the animation activity number from an activity string
 *
 * @param activity			The activity string to retrieve from
 *
 * @return					Activity number or -1 on failure
 */
native int AnimGetFromActivity(char[] activity);

methodmap PlayerAnimState {
	// Get the PlayerAnimState instance of a player
	public static native PlayerAnimState FromPlayer(int client);

	// Main activity of player's animation, matching enums in "left4dhooks_anim.inc"
	public native int GetMainActivity();

	// Restart and recalculate the main activity
	public native void ResetMainActivity();

	// All booleans (or flags) that used for animation events
	property bool m_bIsCustomSequence { // True only after "CTerrorPlayerAnimState::SetCustomSequence"
		public native get();
		public native set(bool value);
	}
	property bool m_bIsDead {
		public native get();
		public native set(bool value);
	}
	property bool m_bIsHealing {
		public native get();
		public native set(bool value);
	}
	property bool m_bIsResurrection {
		public native get();
		public native set(bool value);
	}
	property bool m_bIsHitByCharger { // aka multi-charged, bowling
		public native get();
		public native set(bool value);
	}
	property bool m_bIsPummeled {
		public native get();
		public native set(bool value);
	}
	property bool m_bIsSlammedIntoWall {
		public native get();
		public native set(bool value);
	}
	property bool m_bIsSlammedIntoGround {
		public native get();
		public native set(bool value);
	}
	property bool m_bIsStartPummel { // Something to do with charger pummel animation, not sure about the name
		public native get();
		public native set(bool value);
	}
	property bool m_bIsPounded { // Pummel get-up
		public native get();
		public native set(bool value);
	}
	property bool m_bIsCarriedByCharger {
		public native get();
		public native set(bool value);
	}
	property bool m_bIsPunchedByTank { // Rock get-up shares this
		public native get();
		public native set(bool value);
	}
	property bool m_bIsSpitting {
		public native get();
		public native set(bool value);
	}
	property bool m_bIsPouncedOn {
		public native get();
		public native set(bool value);
	}
	property bool m_bIsTongueAttacked {
		public native get();
		public native set(bool value);
	}
	property bool m_bIsStartChainsaw {
		public native get();
		public native set(bool value);
	}
	property bool m_bIsIsPouncing {
		public native get();
		public native set(bool value);
	}
	property bool m_bIsRiding {
		public native get();
		public native set(bool value);
	}
	property bool m_bIsJockeyRidden {
		public native get();
		public native set(bool value);
	}
	property bool m_bIsTonguing {
		public native get();
		public native set(bool value);
	}
	property bool m_bIsCharging {
		public native get();
		public native set(bool value);
	}
	property bool m_bIsPummeling {
		public native get();
		public native set(bool value);
	}
	property bool m_bIsPounding {
		public native get();
		public native set(bool value);
	}
	property bool m_bIsTongueReelingIn {
		public native get();
		public native set(bool value);
	}
	property bool m_bIsTongueAttacking {
		public native get();
		public native set(bool value);
	}
}

methodmap ConVarPtrWrapper {
	/**
	 * @brief Constructor accepting a C++ pointer (address)
	 *
	 * @param p			Pointer (address) of ConVar
	 */
	public ConVarPtrWrapper(Address p) {
		return view_as<ConVarPtrWrapper>(p);
	}

	/**
	 * @brief Retrieves an integer value for the convar
	 */
	public int GetInt() {
		return this.m_pParent.m_nValue;
	}

	/**
	 * @brief Retrieves a float value for the convar
	 */
	public float GetFloat() {
		return this.m_pParent.m_fValue;
	}

	/**
	 * @brief Retrieves the SourceMod Handle for the convar
	 *
	 * @return				SourceMod ConVar handle
	 */
	public ConVar GetSMHandle() {
		char name[MAX_NAME_LENGTH];
		ReadMemoryString(this.m_pszName, name, sizeof(name));
		return FindConVar(name);
	}

	/**
	 * @brief Retrieves the C string pointer for the convar
	 */
	property Address m_pszName {
		public get() { return LoadFromAddress(view_as<Address>(this) + view_as<Address>(12), NumberType_Int32); }
	}

	/**
	 * @brief Retrieves the parent convar
	 * @remarks This either points to "this" or it points to the original declaration of a ConVar
	 * @remarks This allows ConVars to exist in separate modules, and they all use the first one to be declared
	 * @remarks m_pParent->m_pParent must equal m_pParent (ie: m_pParent must be the root, or original, ConVar)
	 */
	property ConVarPtrWrapper m_pParent {
		public get() { return LoadFromAddress(view_as<Address>(this) + view_as<Address>(28), NumberType_Int32); }
	}

	/**
	 * @brief DO NOT USE THIS PROPERTY. USE "GetFloat" INSTEAD. Retrieves the float value stored in this convar struct
	 */
	property float m_fValue {
		public get() { return LoadFromAddress(view_as<Address>(this) + view_as<Address>(44), NumberType_Int32); }
	}

	/**
	 * @brief DO NOT USE THIS PROPERTY. USE "GetInt" INSTEAD. Retrieves the integer value stored in this convar struct
	 */
	property int m_nValue {
		public get() { return LoadFromAddress(view_as<Address>(this) + view_as<Address>(48), NumberType_Int32); }
	}
}

// Used to tell AmmoDef to use the cvars, not the integers
#define		USE_CVAR		-1
// Ammo is infinite
#define		INFINITE_AMMO	-2

methodmap Ammo_t
{
	public native void GetName(char[] buffer, int maxlength);

	property int nDamageType {
		public native get();
		public native set(int nDamageType);
	}

	property int eTracerType {
		public native get();
		public native set(int eTracerType);
	}

	property float physicsForceImpulse {
		public native get();
		public native set(float physicsForceImpulse);
	}

	property int nMinSplashSize {
		public native get();
		public native set(int nMinSplashSize);
	}

	property int nMaxSplashSize {
		public native get();
		public native set(int nMaxSplashSize);
	}

	property int nFlags {
		public native get();
		public native set(int nFlags);
	}

	// Values for player/NPC damage and carrying capability
	// If the integers are set, they override the CVars
	property int pPlrDmg {						// CVar for player damage amount
		public native get();
		public native set(int pPlrDmg);
	}

	property int pNPCDmg {						// CVar for NPC damage amount
		public native get();
		public native set(int pNPCDmg);
	}

	property int pMaxCarry {					// CVar for maximum number can carry
		public native get();
		public native set(int pMaxCarry);
	}

	property ConVarPtrWrapper pPlrDmgCVar {				// CVar for player damage amount
		public native get();
	}

	property ConVarPtrWrapper pNPCDmgCVar {				// CVar for NPC damage amount
		public native get();
	}

	property ConVarPtrWrapper pMaxCarryCVar {				// CVar for maximum number can carry
		public native get();
	}
}

enum AmmoTracer_t
{
	TRACER_NONE,
	TRACER_LINE,
	TRACER_RAIL,
	TRACER_BEAM,
	TRACER_LINE_AND_WHIZ,
};

enum AmmoFlags_t
{
	AMMO_FORCE_DROP_IF_CARRIED = 0x1,
	AMMO_INTERPRET_PLRDAMAGE_AS_DAMAGE_TO_PLAYER = 0x2,
};

methodmap AmmoDef
{
	/**
	 * @brief Retrieves the ammo index (m_nAmmoIndex)
	 * @remarks Start with an index of 1. Subtract by 1 to get the number of total ammo types
	 *
	 * @return				Current top ammo index
	 */
	public static native int GetAmmoIndex();

	/**
	 * @brief Returns a pointer to the Ammo at the Index passed in
	 *
	 * @param nAmmoIndex	Ammo index
	 * @return				Ammo_t methodmap
	 */
	public static native Ammo_t GetAmmoOfIndex(int nAmmoIndex);

	/**
	 * @brief Returns an index for the ammo name
	 *
	 * @param psz			Ammo name
	 * @return				An ammo index if found, -1 otherwise
	 */
	public static native int Index(const char[] psz);

	/**
	 * @brief Retrieves the maximum ammo that a player can carry
	 * @note Returns the value locally calculated using Ammo_t
	 *
	 * @param nAmmoIndex	Ammo index
	 * @return				Ammo count
	 */
	public static native int MaxCarry(int nAmmoIndex);

	/**
	 * @brief Retrieves the maximum ammo that a player can carry
	 * @note Returns the value from the function call
	 * @note Recommended to use this one in order to get values modified by others plugins
	 *
	 * @param nAmmoIndex	Ammo index
	 * @param client		Client index to test
	 * 						Has no actual effect in function, but helps identify who is picking up ammo
	 * @return				Ammo count
	 */
	public static native int MaxCarry_Call(int nAmmoIndex, int client = -1);

	public static native int PlrDamage(int nAmmoIndex);
	public static native int NPCDamage(int nAmmoIndex);
	public static native int DamageType(int nAmmoIndex);
	public static native int Flags(int nAmmoIndex);
	public static native int MinSplashSize(int nAmmoIndex);
	public static native int MaxSplashSize(int nAmmoIndex);
	public static native int TracerType(int nAmmoIndex);
	public static native float DamageForce(int nAmmoIndex);
}

/**
 * Returns zombie player L4D2 zombie class
 *
 * @param client		Player's index
 * @return				Current L4D2ZombieClassType of player
 * @error				Invalid client index
 */
native int GetZombieClass(int client);

/**
 * Set zombie player L4D2 zombie class
 *
 * @param client		Player's index
 * @param class			L4D2ZombieClassType class symbol
 * @noreturn
 * @error				Invalid client index
 */
native void SetZombieClass(int client, int class);

/**
 * Returns ghost state of zombie player
 *
 * @param client		Player index
 * @return				True if player is ghost, false otherwise
 * @error				Invalid client index
 */
native bool IsPlayerGhost(int client);

/**
 * Sets ghost state of zombie player
 *
 * @param client		Player index
 * @param isGhost		Sets ghost status
 * @noreturn
 * @error				Invalid client index
 */
native void SetPlayerGhostState(int client, bool isGhost);

/**
 * Returns ghost spawn state of zombie player
 *
 * @param client		Player index
 * @return				Player's spawn state bits
 * @error				Invalid client index
 */
native int GetPlayerGhostSpawnState(int client);

/**
 * Set zombie player's ghost spawn state bits
 *
 * Note: The game updates spawn state bits every frame
 *
 * @param client		Player index
 * @param bits			Ghost spawn state bits
 * @noreturn
 * @error				Invalid client index
 */
native void SetPlayerGhostSpawnState(int client, int bits);
/**
 * Returns whether player is incapacitated
 *
 * Note: A tank player will return true when in dying animation
 *
 * @param client		Player index
 * @return				True if incapacitated, false otherwise
 * @error				Invalid client index
 */
native bool IsPlayerIncapacitated(int client);

/**
 * Set player's incapacitated state
 *
 * @param client			Player index
 * @param isIncapacitated	Whether the player is incapacitated
 * @noreturn
 * @error					Invalid client index
 */
native void SetPlayerIncapacitatedState(int client, bool isIncapacitated);

/**
 * Gets a client's shove penalty
 * @note The returned value will be between 0 and z_gun_swing_{vs,coop}_max_penalty
 *
 * @param client		Client id
 *
 * @return				Shove penalty or -1 on error
 */
native int GetShovePenalty(int client);

/**
 * Sets a client's shove penalty
 * @note The penalty should be set between 0 and z_gun_swing_{vs,coop}_max_penalty
 *
 * @param client		Client id
 * @param penalty		Shove penalty
 *
 * @noreturn
 */
native void SetShovePenalty(int client, int penalty);

/**
 * Returns tank player's frustration
 *
 * @param client		Player index
 * @return				How frustrated tank player is
 * @error				Invalid client index
 */
native int GetTankFrustration(int client);

/**
 * Set tank player's frustration
 *
 * @param client		Player index
 * @param frustration	How frustrated tank player is
 * @noreturn
 * @error				Invalid client index
 */
native void SetTankFrustration(int client, int frustration);

/**
 * Removes the weapon from a client's weapon slot
 *
 * @param client		Player's index
 * @param slot			Slot index
 * @noreturn
 * @error				Invalid client or lack of mod support
 */
native void RemoveWeaponSlot(int client, int slot);

/**
 * Removes all weapons from a client
 *
 * @param client		Player's index
 * @noreturn
 * @error				Invalid client or lack of mod support
 */
native void RemoveAllWeapons(int client);

/**
 * Returns infected attacker of survivor victim
 *
 * Note: Infected attacker means the infected player that is currently
 * pinning down the survivor. Such as hunter, smoker, charger and jockey
 *
 * You can use the native L4D2_GetSpecialInfectedDominatingMe() which is likely faster, instead of this stock
 *
 * @param client		Survivor client index
 * @return				Infected attacker index, -1 if not found
 * @error				Invalid client index
 */
native int GetInfectedAttacker(int client);

/**
 * Get an entity's world space origin.
 * Note: Not all entities may support "CollisionProperty" for getting the center.
 *
 * @param iEntity 		Entity index to get origin of.
 * @param vecOrigin		Vector to store origin in.
 * @param bCenter		True to get world space center, false otherwise.
 *
 * @error			Invalid entity index.
 **/
native void GetAbsOrigin(int iEntity, float vecOrigin[3], bool bCenter=false);

/**
 * Returns survivor victim of infected attacker
 *
 * Note: Survivor victim means the survivor player that is currently pinned
 * down by an attacker. Such as hunter, smoker, charger and jockey
 *
 * @param client		Infected client index
 * @return				Survivor victim index, -1 if not found
 * @error				Invalid client index
 */
native int GetSurvivorVictim(int client);

/**
 * @brief Returns if the intro cutscene is playing
 *
 * @return			True if the intro cutscene is playing, false otherwise
 */
native int IsInIntro();

/**
 * @brief Returns if Versus team are flipped
 *
 * @return					0=Not flipped. 1=Flipped
 */
native bool AreTeamsFlipped();

/**
 * @brief Returns if is in second round
 *
 * @return			True if int the second round, false otherwise
 */
native int InSecondHalfOfRound();

/*
 * Do not edit below this line!
 */
public Extension __ext_left4deadtoolz =
{
	name = "left4deadtoolz",
	file = "left4deadtoolz.ext",
#if defined AUTOLOAD_EXTENSIONS
	autoload = 1,
#else
	autoload = 0,
#endif
#if defined REQUIRE_EXTENSIONS
	required = 1,
#else
	required = 0,
#endif
};

#if !defined REQUIRE_EXTENSIONS
public void __ext_left4deadtoolz_SetNTVOptional()
{
	MarkNativeAsOptional("IsValidAddress");
	MarkNativeAsOptional("GetGameModeType");
	MarkNativeAsOptional("Deafen");
	MarkNativeAsOptional("GetTempHealth");
	MarkNativeAsOptional("SetTempHealth");
	MarkNativeAsOptional("GetReserveAmmo");
	MarkNativeAsOptional("SetReserveAmmo");
	MarkNativeAsOptional("PlayMusic");
	MarkNativeAsOptional("StopMusic");
	MarkNativeAsOptional("Dissolve");
	MarkNativeAsOptional("OnITExpired");
	MarkNativeAsOptional("EstimateFallingDamage");
	MarkNativeAsOptional("GetEntityWorldSpaceCenter");
	MarkNativeAsOptional("AngularVelocity");
	MarkNativeAsOptional("GetRandomPZSpawnPosition");
	MarkNativeAsOptional("IsTouchingTrigger");
	MarkNativeAsOptional("GetFurthestSurvivorFlow");
	MarkNativeAsOptional("GetFirstSpawnClass");
	MarkNativeAsOptional("SetFirstSpawnClass");
	MarkNativeAsOptional("FindRandomSpot");
	MarkNativeAsOptional("IsVisibleToPlayer");
	MarkNativeAsOptional("GetSpecialInfectedDominatingMe");
	MarkNativeAsOptional("WarpToValidPositionIfStuck");
	MarkNativeAsOptional("HasAnySurvivorLeftSafeArea");
	MarkNativeAsOptional("IsAnySurvivorInStartArea");
	MarkNativeAsOptional("IsAnySurvivorInCheckpoint");
	MarkNativeAsOptional("AreAllSurvivorsInFinaleArea");
	MarkNativeAsOptional("IsInFirstCheckpoint");
	MarkNativeAsOptional("IsInLastCheckpoint");
	MarkNativeAsOptional("IsPositionInFirstCheckpoint");
	MarkNativeAsOptional("IsPositionInLastCheckpoint");
	MarkNativeAsOptional("IsReachable");
	MarkNativeAsOptional("HasPlayerControlledZombies");
	MarkNativeAsOptional("DetonateProjectile");
	MarkNativeAsOptional("TankRockPrj");
	MarkNativeAsOptional("PipeBombPrj");
	MarkNativeAsOptional("MolotovPrj");
	MarkNativeAsOptional("VomitJarPrj");
	MarkNativeAsOptional("GrenadeLauncherPrj");
	MarkNativeAsOptional("PrecacheParticle");
	MarkNativeAsOptional("RemoveEntityDelay");
	MarkNativeAsOptional("GetPointer");
	MarkNativeAsOptional("GetClientFromAddress");
	MarkNativeAsOptional("GetEntityFromAddress");
	MarkNativeAsOptional("ReadMemoryString");
	MarkNativeAsOptional("WriteMemoryString");
	MarkNativeAsOptional("HasMapStarted");
	MarkNativeAsOptional("GetScriptScope");
	MarkNativeAsOptional("GetVScriptEntity");
	MarkNativeAsOptional("ExecVScriptCode");
	MarkNativeAsOptional("GetVScriptOutput");
	MarkNativeAsOptional("SpitterPrj");
	MarkNativeAsOptional("UseAdrenaline");
	MarkNativeAsOptional("RespawnPlayer");
	MarkNativeAsOptional("SetHumanSpec");
	MarkNativeAsOptional("TakeOverBot");
	MarkNativeAsOptional("CanBecomeGhost");
	MarkNativeAsOptional("SetBecomeGhostAt");
	MarkNativeAsOptional("AreWanderersAllowed");
	MarkNativeAsOptional("GetCurrentFinaleStage");
	MarkNativeAsOptional("ForceNextStage");
	MarkNativeAsOptional("GetSurvivalStartTime");
	MarkNativeAsOptional("SetSurvivalStartTime");
	MarkNativeAsOptional("ForceVersusStart");
	MarkNativeAsOptional("ForceSurvivalStart");
	MarkNativeAsOptional("ForceScavengeStart");
	MarkNativeAsOptional("IsTankInPlay");
	MarkNativeAsOptional("DefibByDeadBody");
	MarkNativeAsOptional("GetDirectorScriptScope");
	MarkNativeAsOptional("GetScriptValueInt");
	MarkNativeAsOptional("GetScriptValueFloat");
	MarkNativeAsOptional("GetSurvivorSetMod");
	MarkNativeAsOptional("GetSurvivorSetMap");
	MarkNativeAsOptional("HasConfigurableDifficultySetting");
	MarkNativeAsOptional("IsGenericCooperativeMode");
	MarkNativeAsOptional("IsFinaleEscapeInProgress");
	MarkNativeAsOptional("IsCoopMode");
	MarkNativeAsOptional("IsRealismMode");
	MarkNativeAsOptional("IsSurvivalMode");
	MarkNativeAsOptional("IsScavengeMode");
	MarkNativeAsOptional("IsVersusMode");
	// left4downtown.inc
	MarkNativeAsOptional("RestartScenarioFromVote");
	MarkNativeAsOptional("IsFirstMapInScenario");
	MarkNativeAsOptional("IsMissionFinalMap");
	MarkNativeAsOptional("NotifyNetworkStateChanged");
	MarkNativeAsOptional("StaggerPlayer");
	MarkNativeAsOptional("SendInRescueVehicle");
	MarkNativeAsOptional("ReplaceTank");
	MarkNativeAsOptional("SpawnTank");
	MarkNativeAsOptional("SpawnSpecial");
	MarkNativeAsOptional("SpawnWitch");
	MarkNativeAsOptional("GetWitchCount");
	MarkNativeAsOptional("GetCurrentChapter");
	MarkNativeAsOptional("GetMaxChapters");
	MarkNativeAsOptional("ScavengeBeginRoundSetupTime");
	MarkNativeAsOptional("SpawnAllScavengeItems");
	MarkNativeAsOptional("ResetMobTimer");
	MarkNativeAsOptional("GetPlayerSpawnTime");
	MarkNativeAsOptional("SetPlayerSpawnTime");
	MarkNativeAsOptional("GetVersusMaxCompletionScore");
	MarkNativeAsOptional("SetVersusMaxCompletionScore");
	// MarkNativeAsOptional("GetTeamScore");
	MarkNativeAsOptional("SetPlayerIntensity");
	MarkNativeAsOptional("SetCampaignScores");
	MarkNativeAsOptional("GetMobSpawnTimerRemaining");
	MarkNativeAsOptional("GetMobSpawnTimerDuration");
	MarkNativeAsOptional("ChangeFinaleStage");
	MarkNativeAsOptional("SpawnWitchBride");
	MarkNativeAsOptional("LobbyUnreserve");
	MarkNativeAsOptional("LobbyIsReserved");
	MarkNativeAsOptional("GetLobbyReservation");
	MarkNativeAsOptional("SetLobbyReservation");
	// l4d2weapons.inc
	MarkNativeAsOptional("GetWeaponID");
	MarkNativeAsOptional("IsValidWeapon");
	MarkNativeAsOptional("GetIntWeaponAttribute");
	MarkNativeAsOptional("GetFloatWeaponAttribute");
	MarkNativeAsOptional("SetIntWeaponAttribute");
	MarkNativeAsOptional("SetFloatWeaponAttribute");
	MarkNativeAsOptional("GetMeleeWeaponIndex");
	MarkNativeAsOptional("GetIntMeleeAttribute");
	MarkNativeAsOptional("GetFloatMeleeAttribute");
	MarkNativeAsOptional("GetBoolMeleeAttribute");
	MarkNativeAsOptional("SetIntMeleeAttribute");
	MarkNativeAsOptional("SetFloatMeleeAttribute");
	MarkNativeAsOptional("SetBoolMeleeAttribute");
	// l4d2timers.inc
	MarkNativeAsOptional("CTimerReset");
	MarkNativeAsOptional("CTimerStart");
	MarkNativeAsOptional("CTimerInvalidate");
	MarkNativeAsOptional("CTimerHasStarted");
	MarkNativeAsOptional("CTimerIsElapsed");
	MarkNativeAsOptional("CTimerGetElapsedTime");
	MarkNativeAsOptional("CTimerGetRemainingTime");
	MarkNativeAsOptional("CTimerGetCountdownDuration");
	MarkNativeAsOptional("ITimerStart");
	MarkNativeAsOptional("ITimerInvalidate");
	MarkNativeAsOptional("ITimerHasStarted");
	MarkNativeAsOptional("ITimerGetElapsedTime");
	MarkNativeAsOptional("CTimer_Reset");
	MarkNativeAsOptional("CTimer_Start");
	MarkNativeAsOptional("CTimer_Invalidate");
	MarkNativeAsOptional("CTimer_HasStarted");
	MarkNativeAsOptional("CTimer_IsElapsed");
	MarkNativeAsOptional("CTimer_GetElapsedTime");
	MarkNativeAsOptional("CTimer_GetRemainingTime");
	MarkNativeAsOptional("CTimer_GetCountdownDuration");

	MarkNativeAsOptional("ITimer_Reset");
	MarkNativeAsOptional("ITimer_Start");
	MarkNativeAsOptional("ITimer_Invalidate");
	MarkNativeAsOptional("ITimer_HasStarted");
	MarkNativeAsOptional("ITimer_GetElapsedTime");
	
	MarkNativeAsOptional("CTimer_GetDuration");
	MarkNativeAsOptional("CTimer_SetDuration");

	MarkNativeAsOptional("CTimer_GetTimestamp");
	MarkNativeAsOptional("CTimer_SetTimestamp");

	MarkNativeAsOptional("ITimer_GetTimestamp");
	MarkNativeAsOptional("ITimer_SetTimestamp");
	// direct.inc
	MarkNativeAsOptional("GetVersusCampaignScores");
	MarkNativeAsOptional("SetVersusCampaignScores");
	MarkNativeAsOptional("GetVersusTankFlowPercent");
	MarkNativeAsOptional("SetVersusTankFlowPercent");
	MarkNativeAsOptional("GetVersusWitchFlowPercent");
	MarkNativeAsOptional("SetVersusWitchFlowPercent");
	MarkNativeAsOptional("GetPendingMobCount");
	MarkNativeAsOptional("SetPendingMobCount");
	MarkNativeAsOptional("GetTankPassedCount");
	MarkNativeAsOptional("SetTankPassedCount");
	MarkNativeAsOptional("GetVSCampaignScore");
	MarkNativeAsOptional("SetVSCampaignScore");
	MarkNativeAsOptional("GetVSTankFlowPercent");
	MarkNativeAsOptional("SetVSTankFlowPercent");
	MarkNativeAsOptional("GetVSTankToSpawnThisRound");
	MarkNativeAsOptional("SetVSTankToSpawnThisRound");
	MarkNativeAsOptional("GetVSWitchFlowPercent");
	MarkNativeAsOptional("SetVSWitchFlowPercent");
	MarkNativeAsOptional("GetVSWitchToSpawnThisRound");
	MarkNativeAsOptional("SetVSWitchToSpawnThisRound");
	MarkNativeAsOptional("GetMapMaxFlowDistance");
	MarkNativeAsOptional("GetInvulnerabilityTimer");
	MarkNativeAsOptional("GetTankTickets");
	MarkNativeAsOptional("SetTankTickets");
	MarkNativeAsOptional("TryOfferingTankBot");
	MarkNativeAsOptional("GetFlowDistance");
	MarkNativeAsOptional("DoAnimationEvent");
	MarkNativeAsOptional("GetMobSpawnTimer");
	MarkNativeAsOptional("GetTankCount");
	MarkNativeAsOptional("GetSIClassDeathTimer");
	MarkNativeAsOptional("GetSIClassSpawnTimer");
	MarkNativeAsOptional("GetVSStartTimer");
	MarkNativeAsOptional("GetScavengeRoundSetupTimer");
	MarkNativeAsOptional("GetScavengeOvertimeGraceTimer");
	MarkNativeAsOptional("GetSpawnTimer");
	MarkNativeAsOptional("GetNextShoveTime");
	MarkNativeAsOptional("SetNextShoveTime");
	MarkNativeAsOptional("GetPreIncapHealth");
	MarkNativeAsOptional("SetPreIncapHealth");
	MarkNativeAsOptional("GetPreIncapHealthBuffer");
	MarkNativeAsOptional("SetPreIncapHealthBuffer");
	MarkNativeAsOptional("GetInfernoMaxFlames");
	MarkNativeAsOptional("SetInfernoMaxFlames");
	MarkNativeAsOptional("GetScriptedEventManager");
	// l4d2addresses.txt
	MarkNativeAsOptional("CTerrorPlayer_OnVomitedUpon");
	MarkNativeAsOptional("Charger_ThrowImpactedSurvivor");
	MarkNativeAsOptional("Charger_StartCarryingVictim");
	MarkNativeAsOptional("Charger_PummelVictim");
	MarkNativeAsOptional("Charger_EndPummel");
	MarkNativeAsOptional("Charger_EndCarry");
	MarkNativeAsOptional("Jockey_EndRide");
	MarkNativeAsOptional("Hunter_ReleaseVictim");
	MarkNativeAsOptional("Smoker_ReleaseVictim");
	MarkNativeAsOptional("CancelStagger");
	MarkNativeAsOptional("FindUseEntity");
	MarkNativeAsOptional("ForceHunterVictim");
	MarkNativeAsOptional("ForceSmokerVictim");
	MarkNativeAsOptional("ForceJockeyVictim");
	MarkNativeAsOptional("CreateRescuableSurvivors");
	MarkNativeAsOptional("StopBeingRevived");
	MarkNativeAsOptional("ReviveSurvivor");
	MarkNativeAsOptional("GetHighestFlowSurvivor");
	MarkNativeAsOptional("GetInfectedFlowDistance");
	MarkNativeAsOptional("CleanupPlayerState");
	MarkNativeAsOptional("TakeOverZombieBot");
	MarkNativeAsOptional("ReplaceWithBot");
	MarkNativeAsOptional("CullZombie");
	MarkNativeAsOptional("SetClass");
	MarkNativeAsOptional("MaterializeFromGhost");
	MarkNativeAsOptional("BecomeGhost");
	MarkNativeAsOptional("GoAwayFromKeyboard");
	MarkNativeAsOptional("State_Transition");
	MarkNativeAsOptional("RegisterForbiddenTarget");
	MarkNativeAsOptional("UnRegisterForbiddenTarget");
	MarkNativeAsOptional("IsEntitySaveable");
	MarkNativeAsOptional("CTerrorPlayer_OnHitByVomitJar");
	MarkNativeAsOptional("Infected_OnHitByVomitJar");
	MarkNativeAsOptional("CTerrorPlayer_Fling");
	MarkNativeAsOptional("GetVersusCompletionPlayer");
	MarkNativeAsOptional("SwapTeams");
	MarkNativeAsOptional("EndVersusModeRound");
	MarkNativeAsOptional("StartRematchVote");
	MarkNativeAsOptional("Rematch");
	MarkNativeAsOptional("FullRestart");
	MarkNativeAsOptional("HideVersusScoreboard");
	MarkNativeAsOptional("HideScavengeScoreboard");
	MarkNativeAsOptional("HideScoreboard");

	MarkNativeAsOptional("NavAreaTravelDistance");
	MarkNativeAsOptional("NavAreaBuildPath");
	MarkNativeAsOptional("GetAllNavAreas");
	MarkNativeAsOptional("GetNavAreaID");
	MarkNativeAsOptional("GetNavAreaByID");
	MarkNativeAsOptional("GetNavAreaPos");
	MarkNativeAsOptional("GetNavAreaCenter");
	MarkNativeAsOptional("GetNavAreaSize");
	MarkNativeAsOptional("IsNavAreaConnected");
	MarkNativeAsOptional("IsNavAreaBlocked");
	MarkNativeAsOptional("HasNavAreaSpawnAttributes");
	MarkNativeAsOptional("GetNavAreaSpawnAttributes");
	MarkNativeAsOptional("SetNavAreaSpawnAttributes");
	MarkNativeAsOptional("AddNavAreaSpawnAttributes");
	MarkNativeAsOptional("RemoveNavAreaSpawnAttributes");
	MarkNativeAsOptional("HasNavAreaAttributeFlags");
	MarkNativeAsOptional("GetNavAreaAttributeFlags");
	MarkNativeAsOptional("SetNavAreaAttributeFlags");
	MarkNativeAsOptional("AddNavAreaAttributeFlags");
	MarkNativeAsOptional("RemoveNavAreaAttributeFlags");
	MarkNativeAsOptional("GetTerrorNavArea");
	MarkNativeAsOptional("GetTerrorNavAreaFlow");
	MarkNativeAsOptional("GetNearestNavArea");
	MarkNativeAsOptional("GetLastKnownArea");
	// anim
	MarkNativeAsOptional("AnimHookEnable");
	MarkNativeAsOptional("AnimHookDisable");
	MarkNativeAsOptional("AnimGetActivity");
	MarkNativeAsOptional("AnimGetFromActivity");
	MarkNativeAsOptional("PlayerAnimState.FromPlayer");
	MarkNativeAsOptional("PlayerAnimState.GetMainActivity");
	MarkNativeAsOptional("PlayerAnimState.ResetMainActivity");
	MarkNativeAsOptional("PlayerAnimState.m_bIsCustomSequence.get");
	MarkNativeAsOptional("PlayerAnimState.m_bIsCustomSequence.set");
	MarkNativeAsOptional("PlayerAnimState.m_bIsDead.get");
	MarkNativeAsOptional("PlayerAnimState.m_bIsDead.set");
	MarkNativeAsOptional("PlayerAnimState.m_bIsHealing.get");
	MarkNativeAsOptional("PlayerAnimState.m_bIsHealing.set");
	MarkNativeAsOptional("PlayerAnimState.m_bIsResurrection.get");
	MarkNativeAsOptional("PlayerAnimState.m_bIsResurrection.set");
	MarkNativeAsOptional("PlayerAnimState.m_bIsHitByCharger.get");
	MarkNativeAsOptional("PlayerAnimState.m_bIsHitByCharger.set");
	MarkNativeAsOptional("PlayerAnimState.m_bIsPummeled.get");
	MarkNativeAsOptional("PlayerAnimState.m_bIsPummeled.set");
	MarkNativeAsOptional("PlayerAnimState.m_bIsSlammedIntoWall.get");
	MarkNativeAsOptional("PlayerAnimState.m_bIsSlammedIntoWall.set");
	MarkNativeAsOptional("PlayerAnimState.m_bIsSlammedIntoGround.get");
	MarkNativeAsOptional("PlayerAnimState.m_bIsSlammedIntoGround.set");
	MarkNativeAsOptional("PlayerAnimState.m_bIsStartPummel.get");
	MarkNativeAsOptional("PlayerAnimState.m_bIsStartPummel.set");
	MarkNativeAsOptional("PlayerAnimState.m_bIsPounded.get");
	MarkNativeAsOptional("PlayerAnimState.m_bIsPounded.set");
	MarkNativeAsOptional("PlayerAnimState.m_bIsCarriedByCharger.get");
	MarkNativeAsOptional("PlayerAnimState.m_bIsCarriedByCharger.set");
	MarkNativeAsOptional("PlayerAnimState.m_bIsPunchedByTank.get");
	MarkNativeAsOptional("PlayerAnimState.m_bIsPunchedByTank.set");
	MarkNativeAsOptional("PlayerAnimState.m_bIsSpitting.get");
	MarkNativeAsOptional("PlayerAnimState.m_bIsSpitting.set");
	MarkNativeAsOptional("PlayerAnimState.m_bIsPouncedOn.get");
	MarkNativeAsOptional("PlayerAnimState.m_bIsPouncedOn.set");
	MarkNativeAsOptional("PlayerAnimState.m_bIsTongueAttacked.get");
	MarkNativeAsOptional("PlayerAnimState.m_bIsTongueAttacked.set");
	MarkNativeAsOptional("PlayerAnimState.m_bIsStartChainsaw.get");
	MarkNativeAsOptional("PlayerAnimState.m_bIsStartChainsaw.set");
	MarkNativeAsOptional("PlayerAnimState.m_bIsIsPouncing.get");
	MarkNativeAsOptional("PlayerAnimState.m_bIsIsPouncing.set");
	MarkNativeAsOptional("PlayerAnimState.m_bIsRiding.get");
	MarkNativeAsOptional("PlayerAnimState.m_bIsRiding.set");
	MarkNativeAsOptional("PlayerAnimState.m_bIsJockeyRidden.get");
	MarkNativeAsOptional("PlayerAnimState.m_bIsJockeyRidden.set");
	MarkNativeAsOptional("PlayerAnimState.m_bIsTonguing.get");
	MarkNativeAsOptional("PlayerAnimState.m_bIsTonguing.set");
	MarkNativeAsOptional("PlayerAnimState.m_bIsCharging.get");
	MarkNativeAsOptional("PlayerAnimState.m_bIsCharging.set");
	MarkNativeAsOptional("PlayerAnimState.m_bIsPummeling.get");
	MarkNativeAsOptional("PlayerAnimState.m_bIsPummeling.set");
	MarkNativeAsOptional("PlayerAnimState.m_bIsPounding.get");
	MarkNativeAsOptional("PlayerAnimState.m_bIsPounding.set");
	MarkNativeAsOptional("PlayerAnimState.m_bIsTongueReelingIn.get");
	MarkNativeAsOptional("PlayerAnimState.m_bIsTongueReelingIn.set");
	MarkNativeAsOptional("PlayerAnimState.m_bIsTongueAttacking.get");
	MarkNativeAsOptional("PlayerAnimState.m_bIsTongueAttacking.set");

	MarkNativeAsOptional("GetZombieClass");
    MarkNativeAsOptional("SetZombieClass");
    MarkNativeAsOptional("IsPlayerGhost");
    MarkNativeAsOptional("SetPlayerGhostState");
    MarkNativeAsOptional("GetPlayerGhostSpawnState");
    MarkNativeAsOptional("SetPlayerGhostSpawnState");
    MarkNativeAsOptional("IsPlayerIncapacitated");
    MarkNativeAsOptional("SetPlayerIncapacitatedState");
    MarkNativeAsOptional("GetShovePenalty");
    MarkNativeAsOptional("SetShovePenalty");
    MarkNativeAsOptional("GetTankFrustration");
    MarkNativeAsOptional("SetTankFrustration");
    MarkNativeAsOptional("RemoveWeaponSlot");
    MarkNativeAsOptional("RemoveAllWeapons");
    MarkNativeAsOptional("GetSurvivorVictim");
    MarkNativeAsOptional("GetInfectedAttacker");
    MarkNativeAsOptional("GetAbsOrigin");

	MarkNativeAsOptional("IsInIntro");
	MarkNativeAsOptional("AreTeamsFlipped");
	MarkNativeAsOptional("InSecondHalfOfRound");

	MarkNativeAsOptional("Ammo_t.GetName");
	MarkNativeAsOptional("Ammo_t.nDamageType.get");
	MarkNativeAsOptional("Ammo_t.nDamageType.set");
	MarkNativeAsOptional("Ammo_t.eTracerType.get");
	MarkNativeAsOptional("Ammo_t.eTracerType.set");
	MarkNativeAsOptional("Ammo_t.physicsForceImpulse.get");
	MarkNativeAsOptional("Ammo_t.physicsForceImpulse.set");
	MarkNativeAsOptional("Ammo_t.nMinSplashSize.get");
	MarkNativeAsOptional("Ammo_t.nMinSplashSize.set");
	MarkNativeAsOptional("Ammo_t.nMaxSplashSize.get");
	MarkNativeAsOptional("Ammo_t.nMaxSplashSize.set");
	MarkNativeAsOptional("Ammo_t.nFlags.get");
	MarkNativeAsOptional("Ammo_t.nFlags.set");
	MarkNativeAsOptional("Ammo_t.pPlrDmg.get");
	MarkNativeAsOptional("Ammo_t.pPlrDmg.set");
	MarkNativeAsOptional("Ammo_t.pNPCDmg.get");
	MarkNativeAsOptional("Ammo_t.pNPCDmg.set");
	MarkNativeAsOptional("Ammo_t.pMaxCarry.get");
	MarkNativeAsOptional("Ammo_t.pMaxCarry.set");
	MarkNativeAsOptional("Ammo_t.pPlrDmgCVar.get");
	MarkNativeAsOptional("Ammo_t.pNPCDmgCVar.get");
	MarkNativeAsOptional("Ammo_t.pMaxCarryCVar.get");

	MarkNativeAsOptional("AmmoDef.GetAmmoOfIndex");
	MarkNativeAsOptional("AmmoDef.Index");
	MarkNativeAsOptional("AmmoDef.PlrDamage");
	MarkNativeAsOptional("AmmoDef.NPCDamage");
	MarkNativeAsOptional("AmmoDef.MaxCarry");
	MarkNativeAsOptional("AmmoDef.DamageType");
	MarkNativeAsOptional("AmmoDef.Flags");
	MarkNativeAsOptional("AmmoDef.MinSplashSize");
	MarkNativeAsOptional("AmmoDef.MaxSplashSize");
	MarkNativeAsOptional("AmmoDef.TracerType");
	MarkNativeAsOptional("AmmoDef.DamageForce");
	MarkNativeAsOptional("AmmoDef.GetAmmoIndex");
}
#endif
