#if defined _left4deadtoolz_ammo_included
 #endinput
#endif
#define _left4deadtoolz_ammo_included

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