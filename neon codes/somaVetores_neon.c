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
    float a[8] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0};
    float b[8] = {8.0, 7.0, 6.0, 5.0, 4.0, 3.0, 2.0, 1.0};
    float result[8];

    float32x4_t va = vld1q_f32(a);   // Carrega os primeiros 4 elementos de 'a' em um registrador NEON
    float32x4_t va2 = vld1q_f32(a+4); //Carrega os últimos 4 elementos de 'a' em um registrador NEON
    float32x4_t vb = vld1q_f32(b);//Carrega os primeiros 4 elementos de 'b' em um registrador NEON
    float32x4_t vb2 = vld1q_f32(b+4);   // Carrega os ultimos 4 elementos de 'b' em um registrador NEON
    
    float32x4_t avresult = vaddq_f32(va, vb); // Soma os registradores NEON
    float32x4_t bvresult = vaddq_f32(va2, vb2);

    float32x4_t resultadoFinal = vaddq_f32(bvresult, avresult);
    // Armazena o resultado no vetor 'result'
    vst1q_f32(result, resultadoFinal);// devo colocar um & no result ?... (&result)

    for (int i = 0; i < 4; ++i) {
        printf("%f ", result[i]);
    }
    printf("\n");

    return 0;
}
