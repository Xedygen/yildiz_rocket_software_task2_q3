#include <stdio.h>

enum AccelRange {
    AFS_2G,
    AFS_4G,
    AFS_8G,
    AFS_16G
};

enum AccelBandwidth {
    AFS_7_81Hz,
    AFS_15_63Hz,
    AFS_31_25Hz,
    AFS_62_5Hz,
    AFS_125Hz,
    AFS_250Hz,
    AFS_500Hz,
    AFS_1000Hz
};

enum AccelMode {
    AFS_Normal,
    AFS_Suspend,
    AFS_LowP1,
    AFS_Standby,
    AFS_LowP2,
    AFS_DSuspend
};

int main() {
    typedef struct AccConfigValue {
        enum AccelRange range;
        enum AccelBandwidth bandwidth;
        enum AccelMode mode;
    }AccConfigValue;

    AccConfigValue config;

    /*User config begin*/
    config.bandwidth = AFS_500Hz;
    config.mode = AFS_Normal;
    config.range = AFS_8G;
    /*User config end*/

    int value = 0b00000000;

    value = (config.mode << 5) + (config.bandwidth << 2) +config.range;

    printf("AccConfigvalue(Decimal): %d\n", value);
    printf("AccConfigvalue(Hexadecimal): %x\n", value);
    printf("AccConfigValue(Binary): ");
    for (int i = 8 - 1; i >= 0; i--) {
        putchar((value & (1 << i)) ? '1' : '0');
    }

    return 0;
}