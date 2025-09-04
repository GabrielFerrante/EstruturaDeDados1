O problema de Josephus é um problema teórico relacionado a uma lenda histórica na qual um grupo de soldados judeus, incluindo o historiador Flávio Josefo, estava encurralado por romanos e preferiu um suicídio coletivo a se render. Eles formaram um círculo e decidiram eliminar cada k-ésima pessoa até que apenas uma restasse, que então se renderia. Josefo e um companheiro calcularam suas posições para sobreviver. Matematicamente, o problema envolve determinar a posição de sobrevivência em um círculo de n pessoas, onde cada k-ésima pessoa é eliminada sequencialmente.

### Exemplo com n=5 e k=2:
- **Pessoas numeradas de 1 a 5**.
- **Eliminação a cada 2 pessoas**:
  1. Começando em 1: conta 1→2 (elimina 2). Restam: 1, 3, 4, 5.
  2. Próximo a contar é 3: conta 3→4 (elimina 4). Restam: 1, 3, 5.
  3. Próximo a contar é 5: conta 5→1 (elimina 1). Restam: 3, 5.
  4. Próximo a contar é 3: conta 3→5 (elimina 5). Sobra **3**.

### Solução Recursiva:
A posição do sobrevivente, \( J(n, k) \), pode ser calculada por:
- **Caso base**: \( J(1, k) = 1 \).
- **Passo recursivo**: \( J(n, k) = (J(n-1, k) + k - 1) \mod n + 1 \).

**Cálculo para n=5, k=2**:
- \( J(1, 2) = 1 \)
- \( J(2, 2) = (1 + 2 - 1) \mod 2 + 1 = 2 \mod 2 + 1 = 1 \)
- \( J(3, 2) = (1 + 2 - 1) \mod 3 + 1 = 2 \mod 3 + 1 = 3 \)
- \( J(4, 2) = (3 + 2 - 1) \mod 4 + 1 = 4 \mod 4 + 1 = 1 \)
- \( J(5, 2) = (1 + 2 - 1) \mod 5 + 1 = 2 \mod 5 + 1 = 3 \)

### Caso Especial (k=2):
Se \( n = 2^m + l \), com \( 0 \leq l < 2^m \), então \( J(n, 2) = 2l + 1 \).  
Para n=5: \( 5 = 2^2 + 1 \), então \( J(5, 2) = 2 \times 1 + 1 = 3 \).
