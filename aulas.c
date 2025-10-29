// Alocação estática (array)

// Alocação dinâmica (lista)
// - malloc() -> Memory Allocation [Alocação de memória] | Ele te fornece o espaço, mas não limpa os valores contidos nesse espaço [garbage values]
//    int* vetor = (int*)malloc(5 * sizeof(int));
// - calloc() -> Clear Allocation [Alocação Limpa] | Ele fornece e limpa o espaço solicitado
//     int* vetor = (int*)calloc(5, sizeof(int));
// - free() -> Liberação | Liberar a memória para uso posterior
//     free(vetor);