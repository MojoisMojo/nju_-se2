附件是一个用于嵌入式系统标定的数据文件，文件用段落的方式存储了变量的属性，现要求实现一段代码，对文件进行分析。

要求使用 Jackson 方法完成设计
给定的文件中，仅处理 MEASUREMENT 段落和 CHARACTERISTIC 且值为 value 段落中的内容 // type 是 VALUE
设计一个数据结构，使用者可以方便地通过变量的名字，访问变量的各种属性
跟据你的设计实现代码 C/C++均可。
你的设计是否兼容功能变化，比如需求改为处理所有 CHARACTERISTIC 段落的内容，你的设计需要做怎样的改变呢？说明需要修改的地方？
针对原始需求是否存在比你最初的设计更好的方案，容易地兼容变化呢？

输入：

```mermaid
graph TB
    a2l[文件]
    version[版本信息]
    pro[主体内容]
    header[首部]
    module[模块]
    par[段落 *]
    measure[MEASURE
            MENT段 #]
    charact[CHARAC
            TERISTIC段 #]
    otherP[其他段 #]
    value[值为VALUE #]
    otherV[值为其他 #]
    a2l-->version
    a2l-->pro-->header
    pro-->module-->par-->charact-->value
    charact-->otherV
    par-->measure
    par-->otherP
```

输出

```mermaid
graph TB
    ins[处理指令 *]
    ask[处理查询 #]
    quit[处理退出 #]
    otherI[非法指令 #]

    ins-->ask
    ins-->quit
    ins-->otherI
```

整体概要设计：

```mermaid
graph TB
    exe[输入文件]

    a2l[处理文件]
    version[处理版本信息]
    pro[处理主体内容]
    header[处理首部]
    module[处理模块]
    par[处理段落 *]
    measure[处理
            MEASUREMENT段 #]
    charact[处理
            CHARACTERISTIC段 #]
    otherP[处理
            其他段 #]
    value[处理
            值为VALUE的段 #]
    otherV[处理
            值为其他的段 #]
    
    ins[处理指令 *]
    ask[处理查询 #]
    quit[处理退出 #]
    otherI[非法指令 #]

    exe-->a2l
    exe-->ins

    a2l-->version
    a2l-->pro-->header
    pro-->module-->par-->charact-->value
    charact-->otherV
    par-->measure
    par-->otherP



    ins-->ask
    ins-->quit
    ins-->otherI
```

```a2l
    /begin MEASUREMENT
      /* Name                   */      av14APCoolOut
      /* Long identifier        */      "AN14"
      /* Data type              */      SLONG
      /* Conversion method      */      thothfcu100_CM_int32_mv
      /* Resolution (Not used)  */      0
      /* Accuracy (Not used)    */      0
      /* Lower limit            */      0.0
      /* Upper limit            */      6000.0
      ECU_ADDRESS                       0x400019e0
    /end MEASUREMENT

    /begin CHARACTERISTIC      
      /* Name                   */      AI_LSD_Table_Data
      /* Long Identifier        */      "LSD PWM"
      /* Characteristic Type    */      CURVE
      /* ECU Address            */      0x400540e0
      /* Record Layout          */      Lookup1D_SLONG
      /* Maxdiff                */      0
      /* Conversion Method      */      thothfcu100_CM_int32
      /* Lower Limit            */      0.0
      /* Upper Limit            */      4096.0
      /begin AXIS_DESCR                 
        /* Description of X-Axis Points */
        /* Axis Type            */      COM_AXIS
        /* Reference to Input   */      NO_INPUT_QUANTITY
        /* Conversion Method    */      thothfcu100_CM_int32
        /* Number of Axis Pts   */      4
        /* Lower Limit          */      0.0
        /* Upper Limit          */      5000.0
        AXIS_PTS_REF                    AI_LSD_Table_Bp
      /end AXIS_DESCR
    /end CHARACTERISTIC

    /begin CHARACTERISTIC
      /* Name                   */      cov_hi  
      /* Long Identifier        */      "kp"
      /* Type                   */      VALUE 
      /* ECU Address            */      0x400540c8 
      /* Record Layout          */      Scalar_FLOAT32_IEEE 
      /* Maximum Difference     */      0 
      /* Conversion Method      */      thothfcu100_CM_single 
      /* Lower Limit            */      -3.4E+38 
      /* Upper Limit            */      3.4E+38
    /end CHARACTERISTIC
```
