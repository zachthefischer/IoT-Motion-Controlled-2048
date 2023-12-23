#include <bootutil/sign_key.h>
static unsigned char key[] = {
  0x30, 0x82, 0x01, 0x0a, 0x02, 0x82, 0x01, 0x01, 0x00, 0xe2, 0x48, 0x5f,
  0x31, 0x08, 0x50, 0x2e, 0x4f, 0x6d, 0xbf, 0xcd, 0xd0, 0x09, 0xf1, 0x5c,
  0xd6, 0x08, 0xe9, 0x84, 0xcf, 0x75, 0x2c, 0x88, 0x07, 0xcc, 0x0e, 0xf9,
  0x53, 0xae, 0x4a, 0x9a, 0x93, 0xb4, 0x1b, 0x55, 0x43, 0xb7, 0x7e, 0x10,
  0xa8, 0x50, 0xd9, 0x14, 0x90, 0x05, 0x80, 0x15, 0xa0, 0x8c, 0xdb, 0xdc,
  0x1b, 0x03, 0x56, 0xd6, 0x47, 0x94, 0x44, 0xa1, 0xe8, 0x15, 0xf4, 0x77,
  0x49, 0x60, 0x45, 0x34, 0xa4, 0x17, 0x9a, 0x81, 0xa8, 0xfc, 0xb6, 0xd9,
  0x21, 0xf6, 0x68, 0xfa, 0x7a, 0x13, 0xe5, 0x25, 0xcd, 0xa5, 0x0b, 0x77,
  0x0a, 0x5f, 0xf6, 0x0b, 0x9d, 0x34, 0x8f, 0xc3, 0xf4, 0x91, 0xf7, 0xab,
  0x28, 0x12, 0x52, 0xdc, 0xbb, 0xb2, 0x92, 0x80, 0x98, 0xe2, 0x13, 0x33,
  0xe7, 0xc3, 0x2a, 0x1c, 0x27, 0x98, 0xfc, 0xff, 0x07, 0xdb, 0x5d, 0x16,
  0xd2, 0x50, 0xc1, 0x8e, 0x12, 0xfa, 0x95, 0x98, 0x51, 0x91, 0xbb, 0xf9,
  0xee, 0xc3, 0x65, 0xa4, 0x02, 0xe0, 0xbf, 0xb6, 0xb1, 0xc6, 0x20, 0xc7,
  0x9f, 0xfe, 0x63, 0x61, 0x6a, 0x68, 0xf6, 0x08, 0xca, 0x55, 0x32, 0xc0,
  0x50, 0xdd, 0x8d, 0x52, 0x73, 0x03, 0x7a, 0xbe, 0xd7, 0x32, 0xd9, 0x61,
  0x99, 0x19, 0xff, 0x0d, 0xe6, 0x82, 0xc8, 0x1c, 0x3d, 0x07, 0x1a, 0xe9,
  0xa8, 0x7b, 0xad, 0x75, 0x2c, 0x26, 0x87, 0x3d, 0x67, 0x2b, 0x5a, 0xc4,
  0x7f, 0x70, 0x86, 0x70, 0x8a, 0x7e, 0xed, 0xe9, 0x2f, 0xbe, 0x2a, 0xd5,
  0xb4, 0x33, 0x7b, 0xcc, 0x89, 0xcd, 0x57, 0x08, 0xbb, 0x72, 0xdf, 0x00,
  0x8e, 0xea, 0x8a, 0x2a, 0xa8, 0xa0, 0x1c, 0xb8, 0x8a, 0x61, 0xaf, 0x32,
  0x3d, 0x41, 0xe9, 0xf6, 0xb1, 0xa2, 0x73, 0xc2, 0xff, 0xd1, 0x32, 0x55,
  0x1f, 0xda, 0x09, 0x23, 0xc1, 0x83, 0x51, 0xe1, 0x4f, 0xd5, 0x65, 0x3e,
  0x97, 0x02, 0x03, 0x01, 0x00, 0x01
};
static unsigned int key_len = 270;
const struct bootutil_key bootutil_keys[] = {
    [0] = {
        .key = key,
        .len = &key_len,
    },
};
const int bootutil_key_cnt = 1;
