#include <stdio.h>
#include <immintrin.h>
//Ele soma os elementos do vetor individualmente
int main() {
    float a[8] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0};
    float b[8] = {8.0, 7.0, 6.0, 5.0, 4.0, 3.0, 2.0, 1.0};
    float result[8];

    __m256 avx_a = _mm256_loadu_ps(a);//carrega o vetor float para o m256
    __m256 avx_b = _mm256_loadu_ps(b);//carrega o vetor float para o m256
    __m256 avx_result = _mm256_add_ps(avx_a, avx_b);//soma os dois vetores e adiciona no avx_result
    
    _mm256_storeu_ps(result, avx_result);// armazena o resultado de avx_result em result

    for (int i = 0; i < 8; ++i) {
        printf("%f ", result[i]);
    }
    printf("\n");

    return 0;
}
