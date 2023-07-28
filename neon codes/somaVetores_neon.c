#include <stdio.h>
#include <arm_neon.h>
//Programa NEON que soma dois vetores

/*A função vld1q_f32 é usada para carregar quatro elementos float (128 bits) 
de um endereço de memória contíguo e armazená-los em um único registrador SIMD chamado 
float32x4_t. Isso permite o carregamento paralelo de quatro elementos float em um único 
passo, o que pode melhorar significativamente o desempenho em operações com vetores grandes.*/

/*A função vst1q_f32 é usada para armazenar quatro elementos float (128 bits) de um 
registrador SIMD float32x4_t em um endereço de memória contíguo. Ela é usada para armazenar 
o resultado de operações SIMD de volta à memória principal.*/
int main() {
    //...
    float a[4] = {1.0, 2.0, 3.0, 4.0};
    float a2[4] = {5.0, 6.0, 7.0, 8.0};
    float b[4] = {8.0, 7.0, 6.0, 5.0};
    float b2[4] = {4.0, 3.0, 2.0, 1.0};
    float32x4_t aNEON = vld1q_f32(a);
    float32x4_t a2NEON = vld1q_f32(a2);
    float32x4_t bNEON = vld1q_f32(b);
    float32x4_t b2NEON = vld1q_f32(b2);
    
    float32x4_t resultadoMetadeInicial = vaddq_f32(aNEON, bNEON);
    float32x4_t resultadoMetadeFinal = vaddq_f32(a2NEON, b2NEON);

    printf("Resultado: ");
    for (int i = 0; i < 4; ++i) {
        printf("%f ", resultadoMetadeInicial[i]);
    }
    for (int i = 0;i <4; i++){
        printf("%f ", resultadoMetadeFinal[i]);
    }
    printf("\n");

    return 0;
}
