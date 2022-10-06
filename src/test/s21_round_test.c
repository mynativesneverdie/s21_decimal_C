#include "s21_tests_suite.h"

START_TEST(s21_round_1) {
    s21_decimal dec1;
    dec1.bits[0] = 0b00000000000000000000000010100101;  // -16.5
    dec1.bits[1] = 0b00000000000000000000000000000000;
    dec1.bits[2] = 0b00000000000000000000000000000000;
    dec1.bits[3] = 0b10000000000000010000000000000000;
    s21_decimal result;
    result.bits[0] = 0b00000000000000000000000000010001; // -17
    result.bits[1] = 0b00000000000000000000000000000000;
    result.bits[2] = 0b00000000000000000000000000000000;
    result.bits[3] = 0b10000000000000000000000000000000;
    s21_decimal res1;
    s21_round(dec1, &res1);
    ck_assert_float_eq(res1.bits[0], result.bits[0]);
    ck_assert_float_eq(res1.bits[1], result.bits[1]);
    ck_assert_float_eq(res1.bits[2], result.bits[2]);
    ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_2) {
    s21_decimal dec1;
    dec1.bits[0] = 0b11111111111111111111111111111111;  // 18014398509481.983
    dec1.bits[1] = 0b00000000001111111111111111111111;
    dec1.bits[2] = 0b00000000000000000000000000000000;
    dec1.bits[3] = 0b00000000000000110000000000000000;
    s21_decimal result;
    result.bits[0] = 0b01001101110100101111000110101010;  // 18014398509482
    result.bits[1] = 0b00000000000000000001000001100010;
    result.bits[2] = 0b00000000000000000000000000000000;
    result.bits[3] = 0b00000000000000000000000000000000;
    s21_decimal res1;
    s21_round(dec1, &res1);
    ck_assert_float_eq(res1.bits[0], result.bits[0]);
    ck_assert_float_eq(res1.bits[1], result.bits[1]);
    ck_assert_float_eq(res1.bits[2], result.bits[2]);
    ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_3) {
    s21_decimal dec1;
    dec1.bits[0] = 0b00000000000011110111001001110100;  // -1012.340
    dec1.bits[1] = 0b00000000000000000000000000000000;
    dec1.bits[2] = 0b00000000000000000000000000000000;
    dec1.bits[3] = 0b10000000000000110000000000000000;
    s21_decimal result;
    result.bits[0] = 0b00000000000000000000001111110100;  // -1012
    result.bits[1] = 0b00000000000000000000000000000000;
    result.bits[2] = 0b00000000000000000000000000000000;
    result.bits[3] = 0b10000000000000000000000000000000;
    s21_decimal res1;
    s21_round(dec1, &res1);
    ck_assert_float_eq(res1.bits[0], result.bits[0]);
    ck_assert_float_eq(res1.bits[1], result.bits[1]);
    ck_assert_float_eq(res1.bits[2], result.bits[2]);
    ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_4) {
    s21_decimal dec1;
    dec1.bits[0] = 0b10000000000000000000001111110100;  // 112590205.4327284
    dec1.bits[1] = 0b00000000000001000000000000000000;
    dec1.bits[2] = 0b00000000000000000000000000000000;
    dec1.bits[3] = 0b10000000000001110000000000000000;
    s21_decimal result;
    result.bits[0] = 0b00000110101101011111110101111101;  // 112590205
    result.bits[1] = 0b00000000000000000000000000000000;
    result.bits[2] = 0b00000000000000000000000000000000;
    result.bits[3] = 0b10000000000000000000000000000000;
    s21_decimal res1;
    s21_round(dec1, &res1);
    ck_assert_float_eq(res1.bits[0], result.bits[0]);
    ck_assert_float_eq(res1.bits[1], result.bits[1]);
    ck_assert_float_eq(res1.bits[2], result.bits[2]);
    ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_5) {
    s21_decimal dec1;
    dec1.bits[0] = 0b10000000000000000000001111110100;  // 2147484660
    dec1.bits[1] = 0b00000000000000000000000000000000;
    dec1.bits[2] = 0b00000000000000000000000000000000;
    dec1.bits[3] = 0b00000000000000000000000000000000;
    s21_decimal result;
    result.bits[0] = 0b10000000000000000000001111110100;  // 2147484660
    result.bits[1] = 0b00000000000000000000000000000000;
    result.bits[2] = 0b00000000000000000000000000000000;
    result.bits[3] = 0b00000000000000000000000000000000;
    s21_decimal res1;
    s21_round(dec1, &res1);
    ck_assert_float_eq(res1.bits[0], result.bits[0]);
    ck_assert_float_eq(res1.bits[1], result.bits[1]);
    ck_assert_float_eq(res1.bits[2], result.bits[2]);
    ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_6) {
    s21_decimal dec1;

    dec1.bits[0] = 0b01100011000011111111111111111111;
    dec1.bits[1] = 0b01101011110001110101111000101101;
    dec1.bits[2] = 0b00000000000000000000000000000101;
    dec1.bits[3] = 0b10000000000010100000000000000000;
    s21_decimal result;
    result.bits[0] = 0b01010100000010111110010000000000;
    result.bits[1] = 0b00000000000000000000000000000010;
    result.bits[2] = 0b00000000000000000000000000000000;
    result.bits[3] = 0b10000000000000000000000000000000;
    s21_decimal res1;
    s21_round(dec1, &res1);
    ck_assert_float_eq(res1.bits[0], result.bits[0]);
    ck_assert_float_eq(res1.bits[1], result.bits[1]);
    ck_assert_float_eq(res1.bits[2], result.bits[2]);
    ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_7) {
    s21_decimal dec1;
    dec1.bits[0] = 0b01010101001110101110101110110001; // -987654321287654321
    dec1.bits[1] = 0b00001101101101001101101001011111;
    dec1.bits[2] = 0b00000000000000000000000000000000;
    dec1.bits[3] = 0b10000000000100100000000000000000; // 18
    s21_decimal result;
    result.bits[0] = 0b00000000000000000000000000000001; // -1
    result.bits[1] = 0b00000000000000000000000000000000;
    result.bits[2] = 0b00000000000000000000000000000000;
    result.bits[3] = 0b10000000000000000000000000000000;
    s21_decimal res1;
    s21_round(dec1, &res1);
    ck_assert_float_eq(res1.bits[0], result.bits[0]);
    ck_assert_float_eq(res1.bits[1], result.bits[1]);
    ck_assert_float_eq(res1.bits[2], result.bits[2]);
    ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_8) {
    s21_decimal dec1;
    dec1.bits[0] = 0b10010011111100000001110001010010; // 123.9432567890
    dec1.bits[1] = 0b00000000000000000000000100100000;
    dec1.bits[2] = 0b00000000000000000000000000000000;
    dec1.bits[3] = 0b00000000000010100000000000000000;
    s21_decimal result;
    result.bits[0] = 0b00000000000000000000000001111100; // 124
    result.bits[1] = 0b00000000000000000000000000000000;
    result.bits[2] = 0b00000000000000000000000000000000;
    result.bits[3] = 0b00000000000000000000000000000000;
    s21_decimal res1;
    s21_round(dec1, &res1);
    ck_assert_float_eq(res1.bits[0], result.bits[0]);
    ck_assert_float_eq(res1.bits[1], result.bits[1]);
    ck_assert_float_eq(res1.bits[2], result.bits[2]);
    ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_9) {
    s21_decimal dec1;
    dec1.bits[0] = 0b11001101110001110111110001000000;  // 9999999999999999998889000000
    dec1.bits[1] = 0b00111110001001010000001001100000;
    dec1.bits[2] = 0b00100000010011111100111001011110;
    dec1.bits[3] = 0b10000000000001000000000000000000;
    s21_decimal result;
    result.bits[0] = 0b10100000111111100100111000000100;  // 999999999999999999888900
    result.bits[1] = 0b00011011110011101100110011101101;
    result.bits[2] = 0b00000000000000001101001111000010;
    result.bits[3] = 0b10000000000000000000000000000000;
    s21_decimal res1;
    s21_round(dec1, &res1);
    ck_assert_float_eq(res1.bits[0], result.bits[0]);
    ck_assert_float_eq(res1.bits[1], result.bits[1]);
    ck_assert_float_eq(res1.bits[2], result.bits[2]);
    ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_10) {
    s21_decimal dec1;
    dec1.bits[0] = 0b10100000111111100100111000000100;
    dec1.bits[1] = 0b00011011110011101100110011101101;
    dec1.bits[2] = 0b00000000000000001101001111000010;
    dec1.bits[3] = 0b00000000000000000000000000000000;
    s21_decimal res1;
    s21_round(dec1, &res1);
    s21_decimal result;
    result.bits[0] = 0b10100000111111100100111000000100;
    result.bits[1] = 0b00011011110011101100110011101101;
    result.bits[2] = 0b00000000000000001101001111000010;
    result.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_float_eq(res1.bits[0], result.bits[0]);
    ck_assert_float_eq(res1.bits[1], result.bits[1]);
    ck_assert_float_eq(res1.bits[2], result.bits[2]);
    ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_11) {
    s21_decimal dec1;
    dec1.bits[0] = 0b10010111011100111001111111111111;
    dec1.bits[1] = 0b00111100000010000011000110001101;
    dec1.bits[2] = 0b00000000000000000000000000000001;
    dec1.bits[3] = 0b00000000000001110000000000000000;
    s21_decimal res1;
    s21_round(dec1, &res1);
    s21_decimal result;
    result.bits[0] = 0b00110110101101101000110001000000;
    result.bits[1] = 0b00000000000000000000001000010010;
    result.bits[2] = 0b00000000000000000000000000000000;
    result.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_float_eq(res1.bits[0], result.bits[0]);
    ck_assert_float_eq(res1.bits[1], result.bits[1]);
    ck_assert_float_eq(res1.bits[2], result.bits[2]);
    ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_12) {
    s21_decimal dec1;
    dec1.bits[0] = 0b10010111011100111001111111111111;
    dec1.bits[1] = 0b00111100000010000011000110001101;
    dec1.bits[2] = 0b00000000000000000000000000000001;
    dec1.bits[3] = 0b10000000000001110000000000000000;
    s21_decimal res1;
    s21_round(dec1, &res1);
    s21_decimal result;
    result.bits[0] = 0b00110110101101101000110001000000;
    result.bits[1] = 0b00000000000000000000001000010010;
    result.bits[2] = 0b00000000000000000000000000000000;
    result.bits[3] = 0b10000000000000000000000000000000;
    ck_assert_float_eq(res1.bits[0], result.bits[0]);
    ck_assert_float_eq(res1.bits[1], result.bits[1]);
    ck_assert_float_eq(res1.bits[2], result.bits[2]);
    ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_roundTest1) {
    // 8053
    s21_decimal src1, origin;
    // src1 = 2;

    src1.bits[0] = 2;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000000000000000000000;
    s21_decimal result = {{0, 0, 0, 0}};
    s21_round(src1, &result);
    origin.bits[0] = 2;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_roundTest2) {
    // 8074
    s21_decimal src1, origin;
    // src1 = 3.5;

    src1.bits[0] = 0b00000000000000000000000000100011;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000010000000000000000;
    s21_decimal result = {{0, 0, 0, 0}};
    s21_round(src1, &result);
    origin.bits[0] = 0b00000000000000000000000000000100;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_roundTest3) {
    // 8095
    s21_decimal src1, origin;
    // src1 = -3.5;

    src1.bits[0] = 0b00000000000000000000000000100011;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b10000000000000010000000000000000;
    s21_decimal result = {{0, 0, 0, 0}};
    s21_round(src1, &result);
    origin.bits[0] = 0b00000000000000000000000000000100;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b10000000000000000000000000000000;
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_roundTest4) {
    // 8116
    s21_decimal src1, origin;
    // src1 = 0;

    src1.bits[0] = 0b00000000000000000000000000000000;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000000000000000000000;
    s21_decimal result = {{0, 0, 0, 0}};
    s21_round(src1, &result);
    origin.bits[0] = 0b00000000000000000000000000000000;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_roundTest5) {
    // 8158
    s21_decimal src1, origin;
    // src1 = -545454512454545.35265;

    src1.bits[0] = 0b11011110101101001010101001100001;
    src1.bits[1] = 0b11110100111110000101111011101001;
    src1.bits[2] = 0b00000000000000000000000000000010;
    src1.bits[3] = 0b10000000000001010000000000000000;
    s21_decimal result = {{0, 0, 0, 0}};
    s21_round(src1, &result);
    origin.bits[0] = 0b10000110011101001011101110010001;
    origin.bits[1] = 0b00000000000000011111000000010110;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b10000000000000000000000000000000;
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_roundTest6) {
    // 8179
    s21_decimal src1, origin;
    // src1 = -5.492654545456454545645464;

    src1.bits[0] = 0b00000111100110110001111110011000;
    src1.bits[1] = 0b01100110010010001001000110100011;
    src1.bits[2] = 0b00000000000001001000101100011101;
    src1.bits[3] = 0b10000000000110000000000000000000;
    s21_decimal result = {{0, 0, 0, 0}};
    s21_round(src1, &result);
    origin.bits[0] = 0b00000000000000000000000000000101;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b10000000000000000000000000000000;
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_roundTest7) {
    // 8200
    s21_decimal src1, origin;
    // src1 = 7961327845421.879754123131254;

    src1.bits[0] = 0b01001110111001000011100101110110;
    src1.bits[1] = 0b01001011001101011010000111011001;
    src1.bits[2] = 0b00011001101110010111010010111111;
    src1.bits[3] = 0b00000000000011110000000000000000;
    s21_decimal result = {{0, 0, 0, 0}};
    s21_round(src1, &result);
    origin.bits[0] = 0b10100100000111100100000000101110;
    origin.bits[1] = 0b00000000000000000000011100111101;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_roundTest8) {
    // 8221
    s21_decimal src1, origin;
    // src1 = -12345677.187654345678987654346;

    src1.bits[0] = 0b01111000100010101111010011001010;
    src1.bits[1] = 0b01100010000010101110010010000111;
    src1.bits[2] = 0b00100111111001000001101011010101;
    src1.bits[3] = 0b10000000000101010000000000000000;
    s21_decimal result = {{0, 0, 0, 0}};
    s21_round(src1, &result);
    origin.bits[0] = 0b00000000101111000110000101001101;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b10000000000000000000000000000000;
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_roundTest9) {
    // 8242
    s21_decimal src1, origin;
    // src1 = 2.5986531268974139743;

    src1.bits[0] = 0b10101111110010001101100101011111;
    src1.bits[1] = 0b01101000101000101011010010000001;
    src1.bits[2] = 0b00000000000000000000000000000001;
    src1.bits[3] = 0b00000000000100110000000000000000;
    s21_decimal result = {{0, 0, 0, 0}};
    s21_round(src1, &result);
    origin.bits[0] = 0b00000000000000000000000000000011;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_roundTest10) {
    // 8263
    s21_decimal src1, origin;
    // src1 = 1;

    src1.bits[0] = 0b00000000000000000000000000000001;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000000000000000000000;
    s21_decimal result = {{0, 0, 0, 0}};
    s21_round(src1, &result);
    origin.bits[0] = 0b00000000000000000000000000000001;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_roundTest11) {
    // 8284
    s21_decimal src1, origin;
    // src1 = 1.1;

    src1.bits[0] = 0b00000000000000000000000000001011;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000010000000000000000;
    s21_decimal result = {{0, 0, 0, 0}};
    s21_round(src1, &result);
    origin.bits[0] = 0b00000000000000000000000000000001;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_roundTest12) {
    // 8305
    s21_decimal src1, origin;
    // src1 = -1.1;

    src1.bits[0] = 0b00000000000000000000000000001011;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b10000000000000010000000000000000;
    s21_decimal result = {{0, 0, 0, 0}};
    s21_round(src1, &result);
    origin.bits[0] = 0b00000000000000000000000000000001;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b10000000000000000000000000000000;
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_roundTest13) {
    // 8326
    s21_decimal src1, origin;
    // src1 = 24.56;

    src1.bits[0] = 0b00000000000000000000100110011000;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000100000000000000000;
    s21_decimal result = {{0, 0, 0, 0}};
    s21_round(src1, &result);
    origin.bits[0] = 0b00000000000000000000000000011001;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_roundTest14) {
    // 8347
    s21_decimal src1, origin;
    // src1 = -2.124;

    src1.bits[0] = 0b00000000000000000000100001001100;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b10000000000000110000000000000000;
    s21_decimal result = {{0, 0, 0, 0}};
    s21_round(src1, &result);
    origin.bits[0] = 0b00000000000000000000000000000010;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b10000000000000000000000000000000;
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_round_2_5) {
  s21_decimal dec1;
  dec1.bits[0] = 0b00000000000000000000000000011001;  // 2.5
  dec1.bits[1] = 0b00000000000000000000000000000000;
  dec1.bits[2] = 0b00000000000000000000000000000000;
  dec1.bits[3] = 0b00000000000000010000000000000000;
  s21_decimal result;
  result.bits[0] = 0b00000000000000000000000000000011; // 3
  result.bits[1] = 0b00000000000000000000000000000000;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal res1;
  s21_round(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_3_5) {
  s21_decimal dec1;
  dec1.bits[0] = 0b00000000000000000000000000100011;  // 3.5
  dec1.bits[1] = 0b00000000000000000000000000000000;
  dec1.bits[2] = 0b00000000000000000000000000000000;
  dec1.bits[3] = 0b00000000000000010000000000000000;
  s21_decimal result;
  result.bits[0] = 0b00000000000000000000000000000100; // 4
  result.bits[1] = 0b00000000000000000000000000000000;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal res1;
  s21_round(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

Suite* s21_round_suite(void) {
    Suite * suite = suite_create("ROUND test");

    TCase * tc = tcase_create("round_test");

    tcase_add_test(tc, s21_round_1);
    tcase_add_test(tc, s21_round_2);
    tcase_add_test(tc, s21_round_3);
    tcase_add_test(tc, s21_round_4);
    tcase_add_test(tc, s21_round_5);
    tcase_add_test(tc, s21_round_6);
    tcase_add_test(tc, s21_round_7);
    tcase_add_test(tc, s21_round_8);
    tcase_add_test(tc, s21_round_9);
    tcase_add_test(tc, s21_round_10);
    tcase_add_test(tc, s21_round_11);
    tcase_add_test(tc, s21_round_12);

    tcase_add_test(tc, s21_roundTest1);
    tcase_add_test(tc, s21_roundTest2);
    tcase_add_test(tc, s21_roundTest3);
    tcase_add_test(tc, s21_roundTest4);
    tcase_add_test(tc, s21_roundTest5);
    tcase_add_test(tc, s21_roundTest6);
    tcase_add_test(tc, s21_roundTest7);
    tcase_add_test(tc, s21_roundTest8);
    tcase_add_test(tc, s21_roundTest9);
    tcase_add_test(tc, s21_roundTest10);
    tcase_add_test(tc, s21_roundTest11);
    tcase_add_test(tc, s21_roundTest12);
    tcase_add_test(tc, s21_roundTest13);
    tcase_add_test(tc, s21_roundTest14);

    tcase_add_test(tc, s21_round_2_5);
    tcase_add_test(tc, s21_round_3_5);

    suite_add_tcase(suite, tc);

    return suite;
}