#ifndef TWS_DEFINES_SOCKET_H_
#define TWS_DEFINES_SOCKET_H_

const int   kClientVersion                = 63;
const int   kClientId                     = 0;

// OUTGOING MSG ID
const int   kMsgIdStartApi                = 71;
const int   kMsgIdReqContractData         = 9;
const int   kMsgIdReqMktData              = 1;
const int   kMsgIdReqAccountSummary       = 62;
const int   kMsgIdReqPositions            = 61;
const int   kMsgIdReqHistoricalData       = 20;

// INCOMMING MSG ID
const int TICK_PRICE                = 1;
const int TICK_SIZE                 = 2;
const int ORDER_STATUS              = 3;
const int ERR_MSG                   = 4;
const int OPEN_ORDER                = 5;
const int ACCT_VALUE                = 6;
const int PORTFOLIO_VALUE           = 7;
const int ACCT_UPDATE_TIME          = 8;
const int NEXT_VALID_ID             = 9;
const int CONTRACT_DATA             = 10;
const int EXECUTION_DATA            = 11;
const int MARKET_DEPTH              = 12;
const int MARKET_DEPTH_L2           = 13;
const int NEWS_BULLETINS            = 14;
const int MANAGED_ACCTS             = 15;
const int RECEIVE_FA                = 16;
const int HISTORICAL_DATA           = 17;
const int BOND_CONTRACT_DATA        = 18;
const int SCANNER_PARAMETERS        = 19;
const int SCANNER_DATA              = 20;
const int TICK_OPTION_COMPUTATION   = 21;
const int TICK_GENERIC              = 45;
const int TICK_STRING               = 46;
const int TICK_EFP                  = 47;
const int CURRENT_TIME              = 49;
const int REAL_TIME_BARS            = 50;
const int FUNDAMENTAL_DATA          = 51;
const int CONTRACT_DATA_END         = 52;
const int OPEN_ORDER_END            = 53;
const int ACCT_DOWNLOAD_END         = 54;
const int EXECUTION_DATA_END        = 55;
const int DELTA_NEUTRAL_VALIDATION  = 56;
const int TICK_SNAPSHOT_END         = 57;
const int MARKET_DATA_TYPE          = 58;
const int COMMISSION_REPORT         = 59;
const int POSITION_DATA             = 61;
const int POSITION_END              = 62;
const int ACCOUNT_SUMMARY           = 63;
const int ACCOUNT_SUMMARY_END       = 64;
const int VERIFY_MESSAGE_API        = 65;
const int VERIFY_COMPLETED          = 66;
const int DISPLAY_GROUP_LIST        = 67;
const int DISPLAY_GROUP_UPDATED     = 68;

#define DECODE(x) \
  decoded = Decoder::Decode(&buf[processed], size - processed, x); \
  if (decoded < 0) { \
    return -1; \
  } \
  processed += decoded;

#define ENCODE(x) \
  Encoder::Encode(oss, x);

#endif //TWS_DEFINES_SOCKET_H_
