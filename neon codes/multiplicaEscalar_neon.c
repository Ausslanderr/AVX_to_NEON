#include <arm_neon.h>
#include <stdio.h>

int main() {
    float a[8] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0};
    float scalar = 2.0;
    float result[8];

    float32x4_t neon_a1 = vld1q_f32(a);
    float32x4_t neon_a2 = vld1q_f32(a + 4);
    float32x4_t neon_scalar = vdupq_n_f32(scalar);

    // Multiplica cada elemento do vetor por um escalar
    float32x4_t neon_result1 = vmulq_f32(neon_a1, neon_scalar);
    float32x4_t neon_result2 = vmulq_f32(neon_a2, neon_scalar);
    vst1q_f32(result, neon_result1);
    vst1q_f32(result + 4, neon_result2);

    printf("Result: ");
    for (int i = 0; i < 8; ++i) {
        printf("%f ", result[i]);
    }
    printf("\n");

    return 0;
}
