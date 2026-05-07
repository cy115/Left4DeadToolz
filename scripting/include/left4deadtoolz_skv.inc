#if defined _left4deadtoolz_skv_included
 #endinput
#endif
#define _left4deadtoolz_skv_included

methodmap SourceKeyValues {
    /**
     * 创建 KeyValues 对象
     *
     * @param name        KeyValues 的名称
     */
    public native SourceKeyValues(const char[] name);
    
    /**
     * 设置是否使用转义序列
     *
     * @param state       是否使用转义序列
     */
    public native void UsesEscapeSequences(bool state);
    
    /**
     * 从文件加载 KeyValues 数据
     *
     * @param file        文件路径
     * @param pathID      路径标识符，默认为 NULL_STRING
     * @return            是否成功加载
     */
    public native bool LoadFromFile(const char[] file, const char[] pathID = NULL_STRING);
    
    /**
     * 检查 KeyValues 对象是否为 null
     *
     * @return            是否为 null
     */
    public native bool IsNull();
    
    /**
     * 获取 KeyValues 的名称
     *
     * @param name        存储名称的缓冲区
     * @param maxlength   缓冲区最大长度
     */
    public native void GetName(char[] name, int maxlength);
    
    /**
     * 设置 KeyValues 的名称
     *
     * @param setName     要设置的名称
     */
    public native void SetName(const char[] setName);
    
    /**
     * 获取 KeyValues 的名称符号
     *
     * @return            名称符号
     */
    public native int GetNameSymbol();
    
    /**
     * 获取指定键的数据类型
     *
     * @param key         键名
     * @return            数据类型
     */
    public native any GetDataType(const char[] key);
    
    /**
     * 获取字符串值
     *
     * @param key         键名
     * @param value       存储值的缓冲区
     * @param maxlength   缓冲区最大长度
     * @param defvalue    默认值
     */
    public native void GetString(const char[] key, char[] value, int maxlength, const char[] defvalue = "");
    
    /**
     * 设置字符串值
     *
     * @param key         键名
     * @param value       要设置的值
     */
    public native void SetString(const char[] key, const char[] value);
    
    /**
     * 设置字符串值（无键名）
     *
     * @param value       要设置的值
     */
    public native void SetStringValue(const char[] value);
    
    /**
     * 获取整数值
     *
     * @param key         键名
     * @param defvalue    默认值
     * @return            整数值
     */
    public native int GetInt(const char[] key, int defvalue = 0);
    
    /**
     * 设置整数值
     *
     * @param key         键名
     * @param value       要设置的值
     */
    public native void SetInt(const char[] key, int value);
    
    /**
     * 获取浮点数值
     *
     * @param key         键名
     * @param defvalue    默认值
     * @return            浮点数值
     */
    public native float GetFloat(const char[] key, float defvalue = 0.0);
    
    /**
     * 设置浮点数值
     *
     * @param key         键名
     * @param value       要设置的值
     */
    public native void SetFloat(const char[] key, float value);
    
    /**
     * 获取指针值
     *
     * @param key         键名
     * @param defvalue    默认值
     * @return            指针值
     */
    public native Address GetPtr(const char[] key, Address defvalue = Address_Null);
    
    /**
     * 查找键
     *
     * @param key         键名
     * @param bCreate     如果不存在是否创建
     * @return            找到的 KeyValues 对象
     */
    public native SourceKeyValues FindKey(const char[] key, bool bCreate = false);
    
    /**
     * 从符号查找键
     *
     * @param keySymbol   键符号
     * @return            找到的 KeyValues 对象
     */
    public native SourceKeyValues FindKeyFromSymbol(int keySymbol);
    
    /**
     * 获取第一个子键
     *
     * @return            第一个子键
     */
    public native SourceKeyValues GetFirstSubKey();
    
    /**
     * 获取下一个键
     *
     * @return            下一个键
     */
    public native SourceKeyValues GetNextKey();
    
    /**
     * 获取第一个真正的子键
     *
     * @return            第一个真正子键
     */
    public native SourceKeyValues GetFirstTrueSubKey();
    
    /**
     * 获取下一个真正的子键
     *
     * @return            下一个真正子键
     */
    public native SourceKeyValues GetNextTrueSubKey();
    
    /**
     * 获取第一个值
     *
     * @return            第一个值
     */
    public native SourceKeyValues GetFirstValue();
    
    /**
     * 获取下一个值
     *
     * @return            下一个值
     */
    public native SourceKeyValues GetNextValue();
    
    /**
     * 保存到文件
     *
     * @param file        文件路径
     * @param pathID      路径标识符，默认为 NULL_STRING
     * @return            是否成功保存
     */
    public native bool SaveToFile(const char[] file, const char[] pathID = NULL_STRING);
}

/**
 * @brief Use to call virtual function MatchExtL4D::GetAllMissions.
 *
 * @return              Missions KeyValues.
 */
native SourceKeyValues GetAllMission();