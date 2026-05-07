#if defined _left4deadtoolz_timer_included
 #endinput
#endif
#define _left4deadtoolz_timer_included

enum L4D2CountdownTimer {
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

enum L4D2IntervalTimer {
    L4D2IT_SmokerDeathTimer,
    L4D2IT_BoomerDeathTimer,
    L4D2IT_HunterDeathTimer,
    L4D2IT_SpitterDeathTimer,
    L4D2IT_JockeyDeathTimer,
    L4D2IT_ChargerDeathTimer
};

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
enum CountdownTimer
{
    CTimer_Null = 0 /*< Invalid Timer when lookup fails */
};

methodmap CountdownTimer {
    /**
     * Reset a CountdownTimer to begin counting down again from now to its original duration
     *
     * @noreturn
     */
    public native void Reset();

    /**
     * Start a CountdownTimer from now for a given duration
     *
     * @param duration			Duration for this CountdownTimer to use, in seconds
     *
     * @noreturn
     */
    public native void Start(float duration);

    /**
     * Invalidate a CountdownTimer, so it is considered not running
     *
     * @noreturn
     */
    public native void Invalidate();

    /**
     * Determine if a CountdownTimer has started counting down
     *
     * @return					True if it has started running, False if it is not (Invalidated)
     */
    public native bool HasStarted();

    /**
     * Determine if a CountdownTimer is elapsed
     *
     * @return					True if the timer's duration has passed since it started, false otherwise
     */
    public native bool IsElapsed();

    /**
     * Check how long a CountdownTimer has been running
     *
     * @return					Time since the CountdownTimer was last Started or Reset, in seconds
     */
    public native float GetElapsedTime();

    /**
     * Check how much time remains before a CountdownTimer is elapsed
     *
     * @return					Time until the CountdownTimer is elapsed, in seconds
     */
    public native float GetRemainingTime();

    /**
     * Get the countdown duration used for a CountdownTimer
     *
     * @return					Countdown duration in seconds if timer is running, or 0.0 if timer is invalidated (not running)
     */
    public native float GetCountdownDuration();

    /**
     * Get the countdown duration used for a CountdownTimer
     *
     * @return					Countdown duration in seconds if timer is running, or 0.0 if timer is invalidated (not running)
     */
    public native float GetDuration();

    /**
     * Set the countdown duration used for a CountdownTimer
     *
     * @param duration			Duration in seconds to set for this timer
     *
     * @noreturn
     */
    public native void SetDuration(float duration);

    /**
     * Get the timestamp used for a CountdownTimer
     *
     * @return					Time in seconds of the timestamp for this timer, or -1.0f if timer is invalidated (not running)
     */
    public native float GetTimestamp();

    /**
     * Set the timestamp used for a CountdownTimer
     *
     * @param timestamp			Timestamp in seconds to set for this timer, or -1.0f to invalidate the timer (considered not running)
     *
     * @noreturn
     */
    public native void SetTimestamp(float timestamp);
};

/* IntervalTimer funcs */
enum IntervalTimer
{
    ITimer_Null = 0 /*< Invalid Timer when lookup fails */
};

methodmap IntervalTimer {
    /**
     * Reset an IntervalTimer to begin counting up again from now
     *
     * @noreturn
     */
    public native void Reset();

    /**
     * Start an IntervalTimer to begin counting up from now
     *
     * @note This is the same as reset for IntervalTimers
     *
     * @noreturn
     */
    public native void Start();

    /**
     * Invalidate an IntervalTimer, so it is considered not running
     *
     * @noreturn
     */
    public native void Invalidate();

    /**
     * Check if an IntervalTimer has started
     *
     * @return					True if the IntervalTimer is running, false if it is Invalidated
     */
    public native bool HasStarted();

    /**
     * Get the elapsed time of an IntervalTimer
     *
     * @return					Elapsed time of the IntervalTimer in seconds if it has started, or 99999.9 ("infinite") if it is Invalidated
     */
    public native float GetElapsedTime();

    /**
     * Get the timestamp used for an IntervalTimer
     *
     * @return					Time in seconds of the timestamp for this timer, or -1.0f if timer is invalidated (not running)
     */
    public native float GetTimestamp();

    /**
     * Set the timestamp used for an IntervalTimer
     *
     * @param timestamp			Timestamp in seconds to set for this timer, or -1.0f to invalidate the timer (considered not running)
     *
     * @noreturn
     */
    public native void SetTimestamp(float timestamp);
};