# Rat in a Maze

O algoritmo "Rat in a Maze" (Rato no Labirinto) é um problema clássico de backtracking que envolve encontrar todos os caminhos possíveis para um rato se mover do ponto de partida (0,0) até o destino (n-1,n-1) em um labirinto.

## Componentes Principais do Algoritmo:

- O labirinto é representado como uma matriz quadrada n x n
- Células com valor 1 são caminhos válidos
- Células com valor 0 são obstáculos/bloqueios

### Movimentos Permitidos
O rato pode se mover em quatro direções:
- **Down (D)**: Para baixo (aumenta a linha)
- **Left (L)**: Para esquerda (diminui a coluna)
- **Right (R)**: Para direita (aumenta a coluna)
- **Up (U)**: Para cima (diminui a linha)

###  Mecanismo de Backtracking
O algoritmo utiliza uma abordagem de backtracking (retrocesso) que:
- Tenta todos os caminhos possíveis
- Volta atrás quando encontra um beco sem saída
- Mantém registro dos caminhos válidos

## Passos do Algoritmo:

1. **Inicialização**:
   - Começa na posição (0,0)
   - Verifica se a célula inicial e final são acessíveis

2. **Exploração Recursiva**:
   - Marca a célula atual como visitada (para evitar ciclos)
   - Tenta mover-se em todas as direções possíveis
   - Para cada movimento válido:
     - Adiciona a direção ao caminho atual
     - Chama recursivamente a função para a nova posição
     - Remove a última direção ao retroceder (backtrack)

3. **Condição de Término**:
   - Quando atinge o destino (n-1,n-1), armazena o caminho encontrado
   - Retorna e continua explorando outros caminhos possíveis

4. **Restauração do Estado**:
   - Ao retroceder, desmarca a célula atual para permitir outros caminhos

## Complexidade:
- **Temporal**: O(4^(n²)) no pior caso (cada célula tem 4 opções)
- **Espacial**: O(n²) devido à profundidade máxima da recursão
