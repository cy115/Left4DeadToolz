#if defined _left4deadtoolz_nav_included
 #endinput
#endif
#define _left4deadtoolz_nav_included

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

// NavArea Spawn Attributes:
enum {
    NAV_NORTH = 0,
    NAV_EAST = 1,
    NAV_SOUTH = 2,
    NAV_WEST = 3,
    NAV_ALL = 4
};

methodmap NavArea {
    /**
     * @brief Returns a given NavArea address from it's ID
     * @remarks Can only be called 1 frame after OnMapStart at the earliest otherwise the addresses are invalid - Since version 1.133 Left4DHooks will block these calls and log an error
     *
     * param id			The NavArea ID
     *
     * @return			NavArea
     */
    public static native NavArea GetByID(int id);

    /**
     * Get the TerrorNavArea which holds a specific position
     * @note Some positions will not return a nav area (Address_Null). Notable examples are saferooms and small ledges like the guard rail at the start of c2m1_highway
     * @remarks This is less reliable than TerrorNavArea.GetNearestNavArea
     *
     * @param pos			The position to find the containing nav area of
     * @param beneathLimit
     *
     * @return				NavArea
     * @error				Unable to prepare SDK call
     */
    public static native NavArea GetNavArea(const float pos[3], float beneathLimit = 120.0)

    /**
     * @brief Returns the nav address of the last known area
     *
     * @param client			The client to check
     *
     * @return					The NavArea
     */
    public static native NavArea GetLastKnownArea(int client);

    /**
     * @brief Returns true if the NavArea is valid
     *
     * @return					True if the NavArea is valid, false otherwise
     */
    public native bool IsValid();
    /**
     * @brief Returns origin of a given NavArea
     *
     * param vecPos		The vector to store the position read
     *
     * @noreturn
     */
    public native void GetPos(float vecPos[3]);

    /**
     * @brief Returns center of a given NavArea
     *
     * param vecPos	    The vector to store the center position
     *
     * @noreturn
     */
    public native void GetCenter(float vecPos[3]);

    /**
     * @brief Returns size of a given NavArea
     *
     * param vecSize	The vector to store the size read
     *
     * @noreturn
     */
    public native void GetSize(float vecSize[3]);

    /**
     * @brief Returns the nav area ID
     *
     * @return			NavArea ID
     */
    property int m_id {
        public native get();
    }

    /**
     * @brief Returns true if the nav area is underwater
     *
     * @return			True if the nav area is underwater, false otherwise
     */
    property bool m_isUnderwater {
        public native get();
    }

    /**
     * @brief Returns if active survivors in the nav area
     *
     * @return			True if there are active survivors in the nav area, false otherwise
     */
    property bool m_activeSurvivors {
        public native get();
    }

    /**
     * @brief Adjust the nav area has attribute flags
     * @remarks See the "NAV_BASE_*" near the top of the include file
     *
     * param flags				Attribute flags to set
     *
     * @return					True if the area has the specified attribute flags, false otherwise
     */
    public native bool HasAttributeFlags(int flags);

    /**
     * @brief Returns the nav area attribute flags
     * @remarks See the "NAV_BASE_*" near the top of the include file
     *
     * @return			Attribute flags
     */
    public native int GetAttributeFlags();

    /**
     * @brief Sets the nav area attribute flags
     * @remarks See the "NAV_BASE_*" near the top of the include file
     *
     * @param flags				Attribute flags to set
     *
     * @noreturn
     */
    public native void SetAttributeFlags(int flags);

    /**
     * @brief add the nav area attribute flags
     * @remarks See the "NAV_BASE_*" near the top of the include file
     *
     * @param flags				Attribute flags to set
     *
     * @noreturn
     */
    public native void AddAttributeFlags(int flags);

    /**
     * @brief remove the nav area attribute flags
     * @remarks See the "NAV_BASE_*" near the top of the include file
     *
     * @param flags				Attribute flags to set
     *
     * @noreturn
     */
    public native void RemoveAttributeFlags(int flags);

    /**
     * @brief Test if a path can be built to the destination area
     * @remarks Uses the "ShortestPathCost" system
     *
     * @param destArea			The NavArea address to test a path to
     * @param flMaxPathLength	Maximum distance allowed between the two points
     * @param teamID			Which team to validate the path for
     * @param ignoreNavBlockers	Should nav blockers be ignored or not
     *
     * @return					Returns true if a path exists, false if not or on script error
     */
    public native bool BuildPathTo(NavArea destArea, float flMaxPathLength = 0.0, int teamID = 2, bool ignoreNavBlockers = false);

    /**
     * @brief Returns true if this area is connected to other area in given direction. (If you set direction to -1 or 4, it will automatically check all directions for a connection)
     *
     * @param destArea		    The NavArea address to test a connection to
     * @param direction 	    The direction to check in (NAV_NORTH, NAV_EAST, NAV_SOUTH, NAV_WEST, NAV_ALL) - provide value 1 to 4 only
     *
     * @return			        Returns true if the areas are connected in the specified direction, false if not or on script error
     */
    public native bool IsConnectedTo(NavArea destArea, int direction);

    /**
     * @brief Return true if team is blocked in this area
     *
     * param team		        The team to test or -1 (possibly checks for all teams)
     * param affectsFlow	    Does this blocked area affect the flow
     *
     * @return			        Result of calculation, true or false
     */
    public native bool IsBlocked(int team, bool affectsFlow);
};

methodmap TerrorNavArea < NavArea {
    /**
     * @brief Given a vector position, returns the relative NavArea
     * @remarks This is more reliable than NavArea.GetNavArea
     *
     * @param vecPos			The vector array to use to retrieve the NavArea
     * @param maxDist			Furthest distance to the nearest nav area
     * @param anyZ				Any ground position?
     * @param checkLOS			Check line of sight
     * @param checkGround		Check if on ground?
     * @param teamID			Team ID to check for
     *
     * @return					The TerrorNavArea value, or 0 on failure probably
     */
    public static native TerrorNavArea GetNearestNavArea(const float vecPos[3], float maxDist = 300.0, bool anyZ = false, bool checkLOS = false, bool checkGround = false, int teamID = 2);
    /**
     * @brief Adjust the nav area has attribute flags
     * @remarks See the "NAV_SPAWN_*" near the top of the include file
     *
     * param flags				Attribute flags to set
     *
     * @return					True if the area has the specified attribute flags, false otherwise
     */
    public native bool HasSpawnAttributes(int flags);

    /**
     * @brief Returns the terror nav area attribute flags
     * @remarks See the "NAV_SPAWN_*" near the top of the include file
     *
     * @return			Attribute flags
     */
    public native int GetSpawnAttributes();

    /**
     * @brief Sets the terror nav area attribute flags
     * @remarks See the "NAV_SPAWN_*" near the top of the include file
     *
     * @param flags				Attribute flags to set
     *
     * @noreturn
     */
    public native void SetSpawnAttributes(int flags);

    /**
     * @brief add the terror nav area attribute flags
     * @remarks See the "NAV_SPAWN_*" near the top of the include file
     *
     * @param flags				Attribute flags to set
     *
     * @noreturn
     */
    public native void AddSpawnAttributes(int flags);

    /**
     * @brief remove the terror nav area attribute flags
     * @remarks See the "NAV_SPAWN_*" near the top of the include file
     *
     * @param flags				Attribute flags to set
     *
     * @noreturn
     */
    public native void RemoveSpawnAttributes(int flags);

    /**
     * Find the distance through the map (in flow units) that a TerrorNavArea is located
     *
     * @return					The flow units through the map that the TerrorNavArea is located at
     * @error					When passed an Address_Null
     */
    property float m_flow {
        public native get();
    }

    /**
     * @brief Given a nav area value, returns a randomly selected position for spawning
     * @remarks This is what Witches use to spawn
     *
     * @param vecPos			The vector array to store the valid location on success
     *
     * @noreturn
     */
    public native void FindRandomSpot(float vecPos[3]);

    /**
     * @brief Returns the next nav area in the escape route
     *
     * @param direction         The direction to check in (NAV_NORTH, NAV_EAST, NAV_SOUTH, NAV_WEST) - provide value 0 to 3 only. Will be set to the direction of the escape step if a valid escape step is found
     *
     * @return					The next nav area in the escape route, or 0 if there are no more areas in the route
     */
    public native TerrorNavArea GetNextEscapeStep(int &direction = 0);

    /**
     * @brief Returns true if the nav area is valid for wandering population
     *
     * @return					True if the nav area is valid for wandering population, false otherwise
     */
    public native bool IsValidForWanderingPopulation();
};

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
 * @brief Returns all TheNavAreas addresses
 * @remarks Can only be called 1 frame after OnMapStart at the earliest otherwise the addresses are invalid - Since version 1.133 Left4DHooks will block these calls and log an error
 *
 *param aList		The ArrayList to store all nav area addresses
 *
 * @noreturn
 */
native void GetAllNavAreas(ArrayList aList);