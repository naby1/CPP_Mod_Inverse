#include <bits/stdc++.h>
#include <openssl/bn.h>
using namespace std;

int main() {

    BIGNUM* e = BN_new();
    const char* e1 = "";
    BN_dec2bn(&e, e1);

    BIGNUM* p = BN_new();
    const char* p1 = "";
    BN_dec2bn(&p, p1);

    BIGNUM* q = BN_new();
    const char* q1 = "";
    BN_dec2bn(&q, q1);

    BN_CTX* ctx = BN_CTX_new();

    BIGNUM* n = BN_new();
    BN_mul(n, p, q, ctx);

    BIGNUM* num1 = BN_new();
    const char* strnum1 = "1";
    BN_dec2bn(&num1, strnum1);
    BIGNUM* p_1 = BN_new();
    BN_sub(p_1, p, num1);
    BIGNUM* q_1 = BN_new();
    BN_sub(q_1, q, num1);

    BIGNUM* fain = BN_new();
    BN_mul(fain, p_1, q_1, ctx);

    BIGNUM* d = BN_new();
    BN_mod_inverse(d, e, fain, ctx);
    char* d1 = BN_bn2dec(d);
    cout << "dec_d:" << d1 << endl;

    return 0;
}
