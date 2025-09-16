
## Métricas de Distância: Euclidiana, Manhattan e Cosseno

Em aprendizado de máquina, ciência de dados e diversas outras áreas da computação, medir a "distância" ou a "similaridade" entre pontos de dados é uma tarefa fundamental. A escolha da métrica correta pode influenciar drasticamente o desempenho de um algoritmo.

Vamos explorar três das métricas mais populares: a Distância Euclidiana, a Distância de Manhattan e a Similaridade de Cosseno (que pode ser facilmente convertida em uma distância).

### 1\. Distância Euclidiana

A Distância Euclidiana é a métrica de distância mais intuitiva e amplamente utilizada. Ela representa a distância em linha reta entre dois pontos em um espaço multidimensional, exatamente como mediríamos com uma régua.

É a raiz da soma das diferenças ao quadrado entre as coordenadas de dois pontos.

#### Fórmula

Para dois pontos, **p** e **q**, em um espaço n-dimensional, onde $p = (p\_1, p\_2, ..., p\_n)$ e $q = (q\_1, q\_2, ..., q\_n)$, a fórmula é:

$$d(p, q) = \sqrt{\sum_{i=1}^{n} (p_i - q_i)^2}$$

#### Interpretação Geométrica

Geometricamente, a Distância Euclidiana corresponde ao comprimento da hipotenusa de um triângulo retângulo, generalizado para múltiplas dimensões (Teorema de Pitágoras).

#### Quando Usar?

  * **Dados Densos e Contínuos:** Funciona muito bem quando seus dados são numéricos, contínuos e o espaço tem um significado "físico", como em dados geoespaciais ou processamento de imagens.
  * **Algoritmos como K-Means:** É a métrica padrão para algoritmos de clusterização como o K-Means.

#### Ponto de Atenção

A Distância Euclidiana é sensível à escala das variáveis. Portanto, é crucial **normalizar ou padronizar** os dados antes de aplicá-la para evitar que atributos com maiores magnitudes dominem o cálculo da distância.

-----

### 2\. Distância de Manhattan

Também conhecida como "distância do táxi" ou "distância L1", a Distância de Manhattan mede a distância entre dois pontos como a soma das diferenças absolutas de suas coordenadas.

O nome vem da ideia de como um táxi se moveria em uma cidade com um layout de grade (como Manhattan), onde só é possível se deslocar ao longo dos eixos horizontais e verticais.

#### Fórmula

Para os mesmos pontos **p** e **q**, a fórmula é:

$$d(p, q) = \sum_{i=1}^{n} |p_i - q_i|$$

#### Interpretação Geométrica

Em vez da hipotenusa, a Distância de Manhattan é o comprimento dos outros dois lados do triângulo retângulo. Ela representa o caminho total percorrido ao longo dos eixos para ir de um ponto a outro.

#### Quando Usar?

  * **Dados de Alta Dimensionalidade:** Em espaços com muitas dimensões (por exemplo, em bioinformática ou análise de texto), a Distância de Manhattan pode ser preferível, pois é menos afetada pela "maldição da dimensionalidade" do que a Euclidiana.
  * **Quando os Eixos São Significativos:** É útil quando o deslocamento em cada eixo tem um significado distinto e não deve ser combinado. Por exemplo, se as características representam "passos" em direções diferentes.

-----

### 3\. Similaridade de Cosseno (e Distância de Cosseno)

Diferente das duas anteriores, a Similaridade de Cosseno não mede a distância em linha reta, mas sim o **cosseno do ângulo** entre dois vetores. Ela avalia a **orientação** (ou direção) dos vetores, e não a sua magnitude.

O resultado varia de -1 a 1:

  * **1:** Os vetores apontam exatamente para a mesma direção.
  * **0:** Os vetores são ortogonais (formam um ângulo de 90°), indicando nenhuma similaridade.
  * **-1:** Os vetores apontam em direções opostas.

#### Fórmula

Para dois vetores **A** e **B**, a fórmula da similaridade de cosseno é:

$$\text{Similaridade} = \cos(\theta) = \frac{A \cdot B}{\|A\| \|B\|} = \frac{\sum_{i=1}^{n} A_i B_i}{\sqrt{\sum_{i=1}^{n} A_i^2} \sqrt{\sum_{i=1}^{n} B_i^2}}$$

Onde:

  * $A . B$ é o produto escalar dos vetores A e B.
  * $|A|$ e $|B|$ são as normas (ou comprimentos) dos vetores A e B.

#### Distância de Cosseno

Para usar a similaridade como uma métrica de distância (onde 0 significa idêntico), podemos convertê-la:

$$\text{Distância de Cosseno} = 1 - \text{Similaridade de Cosseno}$$

O resultado da distância de cosseno varia de 0 (vetores idênticos em orientação) a 2 (vetores opostos).


### Resumo Comparativo

| Métrica | Conceito Chave | Foco | Sensibilidade à Magnitude | Caso de Uso Principal |
| :--- | :--- | :--- | :--- | :--- |
| **Euclidiana** | Menor caminho em linha reta | Distância e Magnitude | Sim | Dados geoespaciais, visão computacional, clusterização geral |
| **Manhattan** | Distância em grade | Distância ao longo dos eixos | Sim | Dados de alta dimensionalidade, features com significados distintos |
| **Cosseno** | Ângulo entre vetores | Orientação / Direção | Não | Análise de texto (NLP), sistemas de recomendação |