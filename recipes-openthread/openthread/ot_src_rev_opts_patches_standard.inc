SRC_URI = "gitsm://github.com/openthread/openthread.git;branch=main;protocol=https"

SRCREV = "5beae143700db54c6e9bd4b15a568abe2f305723"

SRC_URI+="${@bb.utils.contains_any('MACHINE', "imx93evk-matter",  'file://0001-Apply-IW612-change-to-openthread.patch', '', d)}"

EXTRA_OECMAKE = "-GNinja -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DOT_COMPILE_WARNING_AS_ERROR=OFF -DOT_PLATFORM=posix -DOT_SLAAC=ON -DOT_BORDER_AGENT=ON -DOT_BORDER_ROUTER=ON -DOT_COAP=ON -DOT_COAP_BLOCK=ON -DOT_COAP_OBSERVE=ON -DOT_COAPS=ON -DOT_COMMISSIONER=ON -DOT_CHANNEL_MANAGER=ON -DOT_CHANNEL_MONITOR=ON -DOT_CHILD_SUPERVISION=ON -DOT_DATASET_UPDATER=ON -DOT_DHCP6_CLIENT=ON -DOT_DHCP6_SERVER=ON -DOT_DIAGNOSTIC=ON -DOT_DNS_CLIENT=ON -DOT_ECDSA=ON -DOT_IP6_FRAGM=ON -DOT_JAM_DETECTION=ON -DOT_JOINER=ON -DOT_LEGACY=ON -DOT_MAC_FILTER=ON -DOT_NETDIAG_CLIENT=ON -DOT_NEIGHBOR_DISCOVERY_AGENT=ON -DOT_PING_SENDER=ON -DOT_REFERENCE_DEVICE=ON -DOT_SERVICE=ON -DOT_SNTP_CLIENT=ON -DOT_SRP_CLIENT=ON -DOT_COVERAGE=OFF -DOT_LOG_LEVEL_DYNAMIC=ON -DOT_RCP_RESTORATION_MAX_COUNT=2 -DOT_LOG_OUTPUT=PLATFORM_DEFINED -DOT_POSIX_MAX_POWER_TABLE=ON -DOT_DAEMON=ON -DOT_THREAD_VERSION=1.3 -DCMAKE_BUILD_TYPE=Release"

EXTRA_OECMAKE += "${@bb.utils.contains_any('MACHINE', "imx93evk-matter",  ' -DOT_RCP_RESTORATION_MAX_COUNT=5 ', '', d)}"
