
#define common_ticket 0
#define eShop_ticket 1

typedef struct
{
	u8 sig_type[4];
	u8 data[0x100];
	u8 padding[0x3C];
} __attribute__((__packed__)) 
TIK_2048_SIG_CONTEXT;

typedef struct
{
	u8 Issuer[0x40];
	u8 ECDH[0x3c];
	u8 TicketFormatVersion;
	u8 ca_crl_version;
	u8 signer_crl_version;
	u8 EncryptedTitleKey[0x10];
	u8 unknown_0;
	u8 TicketID[8];
	u8 DeviceID[4];
	u8 TitleID[8];
	u8 unknown_1[2];
	u8 TicketVersion[2];
	u8 unused_0[8];
	u8 unused_1;
	u8 CommonKeyID;
	u8 unused_2[0x2F];
	u8 unknown_2;
	u8 unused_3[0x82];
	u8 StaticData[0x30];
	u8 unused_4[0x7C];
} __attribute__((__packed__)) 
TICKET_STRUCTURE;

int GenerateTicket(CIA_CONTEXT *ctx);
int EncryptTitleKey(u8 EncTitleKey[0x10], u8 *DecTitleKey, u8 *CommonKey, u8 *TitleID);
int SetStaticData(u8 mode, u8 section[0x30]);