## D강. 시뮬레이션

https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FnG19u%2FbtqFJbhuD74%2FzfkQ3Ipk2RHJkRDg5YODHk%2Fimg.png![image](https://user-images.githubusercontent.com/83942393/143392712-205cc83c-bf99-4e2f-aa27-6bd6aec64e78.png)
- 이 유형의 문제들이 공통적인 특징을 가지고 있지는 않습니다.
- BFS나 재귀와 같이 특정 자료구조 혹은 알고리즘에 종속되지 않고 주어진 문제 상황을 구현하면 되는데 이 때 구현이 빡세게 필요한 것들을 통틀어서 시뮬레이션 유형이 문제라고 합니다. 
- 시뮬레이션이라는 명칭이 적절한 명칭인지는 잘 모르겠지만 그렇다고 이런 유형들을 빡구현 유형이다, 노가다 유형이다와 같이 말해버리면 특유의 멋이 없으니까 그나마 시뮬레이션이 괜찮은 표현인 것 같습니다.

- 시뮬레이션 유형의 문제들은 배경지식이 거의 필요 없고 구현력을 많이 필요로 합니다.
- 본인의 구현력을 가지고 얼마나 빠르고 정확하게 풀어내는지가 중요한 문제들입니다.

https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FILM31%2FbtqFKKQLXUa%2FV0ss2vWy8CHamL5BR62Kp1%2Fimg.png![image](https://user-images.githubusercontent.com/83942393/143393032-ce3240b2-3fbc-4331-bd47-490a0d07a3d2.png)
- 이번 단원에서는 크게 설명할 건 없고 바로 문제들을 풀어보면서 어떻게 구현을 잘 할 수 있는가를 고민해보면 됩니다. 

- 첫 번째 문제 BOJ 15683번: 감시(CCTV)를 확인해봅시다.
- 삼성 SW 역량테스트 A형은 3시간에 2문제를 주니 1솔브만 목표로 잡더라도 3시간 안에 이 문제를 풀어야 합니다.
- 하지만 첫 문제인 만큼 5시간이 걸리더라도, 아니면 하루 종일 붙잡고 있어야 하더라도 상관없으니 꼭 혼자 힘으로 시도해보면 좋겠습니다.
- 구현이 조금 어려울 수는 있지만 아예 시도조차 못할 난이도는 아닙니다.
- 직접 코드를 작성하고, 주어진 예제를 통해 반례를 찾아 고치고, 맞은 줄 알고 제출했는데 틀려서 코드를 다시 들여다보면서 고민하는 과정들을 거치면서 단순히 강의만 들어서는 얻을 수 없는 많은 것들을 알게 됩니다. 

https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FrBuK7%2FbtqFJaXaOmt%2FLPxYB8MNBweQrtgIzYRDZ0%2Fimg.png![image](https://user-images.githubusercontent.com/83942393/143393494-20000fcb-5140-41d2-b401-f04a07b607de.png)
- 제출했는데 틀렸거나 아예 예제에서 잘못됐다고 해도 너무 절망하지는 마시고 같이 배워보겠습니다.
- 일단 문제를 보면 지문은 길어서 짜증나지만, 그래도 구현을 해야하는게 어떤건지는 굉장히 명확합니다.
- 각 cctv가 가능한 방향은 cctv의 종류에 따라 1, 2, 4개인데 나올 수 있는 모든 조합들을 다 시도하면서 사각지대의 크기를 구하면 그 중에서 최솟값이 답임을 알 수 있습니다.

https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FczibUd%2FbtqFIH2ifAK%2FizUSDX3WrY1B5nUWIMX2FK%2Fimg.png![image](https://user-images.githubusercontent.com/83942393/143394173-e0ce0ca7-1aef-47f8-8578-82d07d37ca69.png)
- 만약에 cctv가 2개라면 (동쪽, 북쪽) 등등 총 16개의 가능성이 있습니다. (4x4)
- 이 각각의 배치들에 대해서 사각 지대의 갯수를 센 후 그중에서 최솟값을 찾아야 합니다. 
- 이렇게 방향을 정하는건 [N과 M(3)](https://www.acmicpc.net/problem/15651) 문제와 판박이라 백트래킹을 이용하면 된다는 걸 알 수 있습니다. 

- 그런데 지금의 상황과 같이 변수들이 가질 수 있는 값이 여러 개이고, 모든 조합을 다 확인해보고 싶은데 변수들끼리는 서로 독립적일 땐 백트래킹을 쓰는 대신 더 쉬운 방법이 있습니다. 
- 바로 진법을 이용한 방법인데 주어진 문제의 상황에서 바로 써보겠습니다.

https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FPHydK%2FbtqFIGI3azN%2FREYpzul33lBS9gxTGrqbok%2Fimg.png![image](https://user-images.githubusercontent.com/83942393/143394534-86bca959-c25c-4417-8018-8daaa61535a8.png)
- 가능한 방향의 종류가 4개이니, 4진법을 쓰면 되고 카메라가 3개라면 나올 수 있는 경우의 수는 4x4x4 = 63이고, 0부터 63까지의 수를 4진법으로 나타내면 000,001, ... 332, 333 까지 입니다. 
- 각각의 자리수를 카메라에 대응시키고, 0~4까지의 값을 방향에 대응시킵니다.
- 즉, 3개의 카메라는 각각 4개의 방향을 가지는 모든 경우의 수가 나옵니다. 
- 중간의 39로 예롤 들어보면 39는 4진수로 2 1 3 이니까 방향을 {2, 1, 3} 으로 둘 수 있습니다.
- 이렇게 하면 총 64가지의 모든 조합을 다 확인해볼 수 있습니다.

100
https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FbitJ3R%2FbtqFK3Jj9pn%2F1BG4Bf5Us6nkH50k6FEq5k%2Fimg.png![image](https://user-images.githubusercontent.com/83942393/143395032-da75dc89-2457-4ffd-b9d8-a96f1fba66c2.png)
- 그렇다면 0부터 63까지의 수를 4진수로 바꾸고 각 자릿수를 얻는 방식으로 코드를 짜야겠다는 생각이 드는데 어떻게 구현할 수 있을까요?
- 일단 10진수에서의 상황을 한 번 보고 가겠습니다.

- 수 3461에서 3, 4, 6, 1 을 추출하고 싶다고 하겠습니다.
- 일단 마지막 자리수인 1은 추출하는 방법이 아주 간단한데 그냥 10으로 나눈 나머지를 반환하면 됩니다.
- 다음은 과감하게 3461을 10으로 나눕니다.
- 그러면 정수 나눗셈의 특성상 자연스럽게 1의 자리수를 버릴 수 있습니다.
- 그러면 346에서 6을 얻는 방법은 또 10으로 나눈 나머지를 반환하면 되고, 이렇게 쭉 진행하면 됩니다.
- 이와 같이 10진법에서의 자릿수를 추출하는데 성공했고, 이걸 4진법에서도 똑같이 하면 됩니다.

- 4로 나눈 나머지를 빼고 4로 나누는걸 반복하면 슬라이드에서의 예시와 같이 39로부터 3, 1, 2를 얻을 수 있습니다.
- 이걸 cctv가 0부터 63에 대해 수행하도록 한 코드를 확인해보겠습니다.
- 연산의 특성상 낮은 자리부터 먼저 출력되서 000 다음에 001이 아니라 100이 나왔지만 결국 출력 결과륿 보면 000부터 333까지 전부 잘 나와 상관이 없는걸 볼 수 있습니다.

- cctv가 k개일 때 0부터 4^k -1 까지에 대해 위의 코드처럼 작성하면 됩니다.
- 코드를 짤 때 tmp 자체를 4로 나누는 대신 brute 와 같은 임시 변수를 둬서 tmp 값을 옮겨담은 후 brute를 4로 나누는지를 고민해보면 좋을 것 같습니다.
- 그리고 아마 이런 의문이 드는 분도 있을 것입니다.
- 1, 3, 4번 cctv는 가능한 방향이 4개인 것은 맞는데, 2번 cctv는 좌우 혹은 상하 2개이고, 5번 cctv는 가능한 방향이 1개입니다.
- 그래서 만약 2번 cctv가 2개 있고, 5번 cctvrk 1개 있다면 가능한 방향 조합의 수는 더 적은데 왜 무조건 4^k를 계산하는걸까요?

- 결론적으로 말해서 좋은 지적입니다.
- 무조건 4개의 방향에 대한 조합으로 코드를 짠다면 이로 인해 중복되는 계산이 발생합니다.
- 하지만 중복된 계산이 있어도 어차피 시간 내로 여유롭게 통과가 되기 때문에 저는 코딩의 예외처리를 줄여 편하게 짜기 위해 굳이 cctv의 종류를 가리지 않고 4^k개를 다 볼 것입니다.
- 이 부분은 조금 있다가 시간복잡도 얘기를 할 때 다시 설명드리겠습니다. 

https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2Fb1YtrZ%2FbtqFIG99ZOB%2FDGmGZPUFLvUIM6T8hHQyv0%2Fimg.png![image](https://user-images.githubusercontent.com/83942393/143397501-3dcfd5ef-6c95-42fd-8d45-1d3fb1eb27b6.png)
- 앞에서 4진법을 이용해 각 cctv의 방향을 잡았다면,그 상황에서 사각 지대의 개수를 세야 합니다.
- 각자 구현 방식이 있는 거고 어떻게든 답만 잘나오면 그만이지만 그래도 잘 조직화된 코드를 보고 좋은 아이디어는 습득하면 문제를 실수없이 빠르게 푸는 데 도움이 되니까 제가 접근한 방법을 알려드리겠습니다.

- 일단 저는 화살표를 따라가면서 벽을 만날때까지 쭉 진행하면서 지나치는 영역에 마크를 남길 예정입니다.
- 그 뒤에 마크가 없는 곳이 몇 개인지를 세면 끝입니다.
- 아이디어 자체는 어떻게 보면 좀 당연해보이는데 실제로 구현을 어떻게 했는지를 코드를 보며 얘기해보겠습니다.

100
https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FbOku8o%2FbtqFJrRUb4a%2FSeCKuNy02eISa9sh06EI0k%2Fimg.png![image](https://user-images.githubusercontent.com/83942393/143399171-13e3db15-3c63-4d10-9c70-eca01c8f4057.png)
- 일단 문제의 특성상 코드가 정말 깁니다. 
- 그래서 부분 부분 끊어서 설명을 하겠습니다. 
- 먼저 변수들에서 dx, dy는 BFS에서 본 것과 같은 쓰임새이고 인덱스 0, 1, 2, 3이 남쪽, 동쪽, 북쪽,서쪽을 가리킵니다. 
- 북쪽을 시작으로 시계방향으로 돌아가는 순서로 되어 있다는걸 확인하고 가겠습니다. 

- board1은 입력으로 주어지는 사무실의 모양을 저장할 변수이고  board2는 cctv의 방향을 정한 후에 cctv의 감시 영역에 걸리는 빈칸은 값을 7로 바꾸는 작업을 할 변수입니다. 
- 그리고 vector cctv는 cctv의 좌표들을 담을 변수입니다. 

- 그 다음 OOB는 (a, b)가 범위를 벗어났는지 체크하는 함수입니다.
- 그 다음으로 나오는 upd 함수가 굉장히 혁신적인 함수인데, 이 함수는 (x, y)에서 dir 방향으로 진행하면서 벽을 만날 때 까지 지나치는 모든 빈 칸을 7로 바꿉니다. 
- 예를 들어 x = 3, y = 1, dir = 2이면 아까 dir = 2이면 북쪽이라고 했으니 (2, 1), (1, 1), (0, 1)에 대해 board2의 해당 칸이 0이면 7로 바꿉니다. 
- 22번째 줄에서의 조건문은 해당 칸에 cctv가 있을 때인데 이 때 break 대신 continue를 해야합니다. 

- 31번째 줄의 변수 mn은 사각 지대의 최소 크기, 즉 답을 저장할 변수입니다. 
- 이후 board1을 입력받으면서 빈칸이 보이면 mn을 1 증가시키니 입력을 받으면서 mn에 일단 빈칸의 개수가 들어갑니다. 
- 문제에 cctv가 1개 이상 있다는 조건이 없어서 cctv가 아예 없는 경우도 고려해야 하니 mn을 0x7f7f7f7f와 같은 값으로 두는 것 보다는 빈칸의 갯수로 맞춰두는게 안전합니다. 

- 그리고 35, 36번째 줄에서 볼 수 있듯 cctv를 찾으면 vector cctv에 추가해줍니다. 
- 이렇게 입력을 처리하고 나면 board1에 입력받은 사무실의 모양이 저장되고 cctv에는 좌표들이 들어가있다는걸 기억하고 다음 슬라이드로 넘어가겠습니다. 

100
https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FbnD0rm%2FbtqFKlqmNNW%2FbVXh6v16PkyqhnTqj2ahe1%2Fimg.png![image](https://user-images.githubusercontent.com/83942393/143400594-5195bfa3-d8f6-4b87-9740-f93ebdc2989d.png)
- 이제 cctv들의 방향을 정할 시간입니다. 
- 앞에서 본 것 처럼 4진법을 이용할거고 cctv가 k개 있다고 할 때 tmp는 0부터 4k-1까지 돌아야 합니다. 
- cmath 헤더에 있는 pow 함수도 쓰는게 바람직하지 않은데 pow 함수는 인자로 실수를 받고 또 실수를 반환하는 함수이기 때문에 물론 지금처럼 cctv의 갯수가 최대 8개여서 48이 double의 유효숫자 범위에 잘 들어올 때에는 운좋게도 오차가 없지만 0x01강에서 다뤘듯이 일반적으로 double은 유효숫자가 15자리인 반면 long long은 19자리이니 정수의 정수 승을 pow 함수로 계산하면 오차가 생길 수 있습니다.

100
https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FbnxqYz%2FbtqFKLIVAOJ%2FGSlAztvtx4zdP64PhoCpRk%2Fimg.png![image](https://user-images.githubusercontent.com/83942393/143400714-d6d74dca-c1b2-4d72-831b-7967ba568fe5.png)
- 이 예시를 보시면 338을 계산할 때 직접 3을 38번 곱하는 대신 pow 함수를 이용했더니 오차가 발생한걸 볼 수 있습니다. 
- 그렇기에 정수의 정수 승을 계산할 때 pow 함수도 쓰면 안됩니다. 
- 대신 지금 p1을 계산한 것 처럼 그냥 정직하게 for문으로 구현하면 됩니다. 
- 그리고 밑이 만약 2, 4, 8과 같이 2의 배수일 때에 한해 특별하게 left shift를 이용할 수 있는데 left shift는 재귀 단원에서 Z를 풀 때 한 번 나왔습니다. 
- 1 << (2\*cctv.size())는 4^cctv.size()이고 left shift가 이질적이다 싶으면 그냥 아까 본 것 처럼 for문을 가지고 4를 여러 번 곱하는 방식으로 구현해도 상관없습니다.

- 41, 42, 43번째 줄에서는 board2에 board1를 복사합니다.
- board1은 원본이고 board2에서는 upd 함수를 거치며 내부의 값이 계속 변경됩니다. 

- 48, 49번째 줄에서는 x, y에 cctv의 좌표를 담습니다. 
- C++11 이상에서는 tie 함수를 사용해 tie(x, y) = cctv[i];로 한 줄에 쓸 수도 있습니다. 
- 살짝 잡기술일수도 있지만 이런거 하나하나가 모여서 코드를 더 그럴싸하게 만드니 보다가 땡기는게 있으면 적극적으로 자기 것으로 만들도록 합시다. 

- 제가 볼 때 50번째 줄부터 이어지는 부분에서 얻을게 많을 것 같습니다. 
- 일단 1번 cctv일 땐  51번째 줄과 같이 upd(x, y, dir)을 실행하는게 너무나 당연하죠. 
- 그 다음 2번 cctv를 보면 dir = 0, 2과 1, 3에 대해 upd를 실행할 수 있어야 하는데 그걸 upd(x, y, dir)과 upd(x, y, dir+2)를 실행하도록 하면서 해결했습니다. 
- brute를 4진법으로 만들어서 추출한 dir이 0일 땐 (0, 2)를, 1일 땐 (1, 3)을, 2일 땐 (2, 4)를, 3일 땐 (3, 5)를 실행할거고 upd 함수에서 dir %= 4가 있기 때문에 자연스럽게 2번 cctv가 놓일 수 있는 2가지 방향을 잘 확인합니다. 
- 이렇게 구현하는 대신 각 카메라 구조에 대한 upd 함수를 다 따로 만들려고 했다면 구현량이 굉장히 늘어났을 것입니다. 
- 또 틀렸을 때 오류를 찾아 바로잡기도 힘들텐데 upd 함수를 1개만 두고 방향으로 잘 조절해서 코드를 깔끔하게 짰습니다. 
- 이후 3, 4, 5번 카메라도 지금의 코드가 맞는지 한 번 생각해봅시다 

- 이렇게 시뮬레이션을 끝낸 뒤에는 빈칸의 갯수를 세고 mn을 갱신합니다. 
- 그리고 모든 방향에 대해 확인한 후에는 mn을 출력합니다. 
- 76번째 줄과 77번째 줄과 같이 코드를 쓰면 타이핑을 아낄 수 있어서 본인이 헷갈리지 않는 선에서는 참고를 좀 하셔도 좋을 것 같습니다. 
- 이해가 갔다 싶으면 제 코드 없이 직접 다시 한 번 짜보도록 하겠습니다.

- 우리는 시간복잡도에 대해 생각해볼 필요가 있습니다. 
- 만약 이 코드의 시간복잡도를 계산했더니 문제의 시간 제한인 1초 안에 들어올 수 없을 것으로 보인다면 최적화를 하거나 아예 다른 방법을 찾아가야 하기 때문입니다.
 
 
https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FbgaQfm%2FbtqFKl40Mv0%2FLvM0uJtSkUZtb3gUf4sH0K%2Fimg.png![image](https://user-images.githubusercontent.com/83942393/143402178-68c29a65-8bd4-431d-864f-309409fa4e5d.png)
- (사무실의 크기 n, m <= 8)
- 일단 각 cctv의 방향을 정했을 때 upd 함수가 최대 몇 번 호출되는지 생각해보면 5번 cctv가 8개일 때 4×8번 호출됩니다. 
- 그리고 upd 함수는 한 줄을 따라 올라가며 해당 칸이 0인지 확인하는 과정을 거치기 때문에 upd 함수의 계산량은 N, M의 최대 크기인 8으로 잡으면 됩니다. 
- upd 함수를 다 본 후에는 NM개의 칸을 살펴보며 빈칸의 개수를 세니까 N = 8, M = 8일 때 64칸을 봐야 합니다. 
- 마지막으로 이 전체 과정을 모든 방향마다 다 해주어야 하니 48이 추가로 곱해져서 이렇게 총 연산량을 구할 수 있고 대략 2000만이니 별 문제 없이 시간내로 잘 통과합니다. 

- 만약 이렇게 계산한 결과가 한 5억 정도로 1초가 간당간당한 상황이라면, 최적화를 시켜야 하는데 
- 예를 들어 cctv가 2번일 때 dir = 2, 3이면 continue를 하고, 5번일 때에는 dir이 0이 아니면 continue를 한다던가, upd 함수에서 0을 7로 바꿀 때마다 전역 변수의 cnt 값을 1 증가시켜 빈 칸을 확인하는 연산량을 절약한다던가 하는 방식을 고민해봤을 것입니다. 
- 하지만 지금은 연산량이 제한 시간 내로 통과하기에 충분하고 0ms로 통과하나 100ms로 통과하나 문제를 맞았다는 사실에는 아무런 차이가 없으니 추가적인 최적화를 진행하지 않겠습니다. 
- 그리고 upd 함수를 이용한 구현을 설명하기 전에 먼저 시간복잡도를 얘기하기가 힘들어서 이 문제에 한해 코드를 제시한 후 시간복잡도를 같이 계산했지만 원래는 풀이를 생각하고 시간복잡도를 생각한 후에 코드 작성에 들어가야 합니다.

- 두 번째 문제 BOJ 18808번: 스티커 붙이기는 제가 만든 문제입니다. 
- 풀이에 대해 얘기하기 전 먼저 풀어보는 시간을 가지면 좋겠고, 일단 풀이를 시작해보겠습니다.

https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FP6MA8%2FbtqFJaQpF0i%2FbkIK2EBydv1hdX6cSX8j91%2Fimg.png![image](https://user-images.githubusercontent.com/83942393/143402625-59c9aaf4-b833-42ae-b15b-98354071ca44.png)
- 과정에서 필요한 절차는 스티커를 특정 영역에 붙일 수 있는지 확인하고 붙이는 것과 스티커를 회전하는 것입니다. 
- 1번은 정말 쉽고 2번은 조금 헷갈릴 수도 있습니다.

100
https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FbJj7Fp%2FbtqFINOGofo%2FfNkfmhrdIg9VLU5kbDHy71%2Fimg.png![image](https://user-images.githubusercontent.com/83942393/143402734-737b835c-c351-4959-8834-e7eb4729efa1.png)
- 모든 칸에 대해 노트북과 스티커가 겹치는 칸이 있는지를 확인하고, 겹치는 칸이 없어서 스티커를 붙이는게 가능하다면 노트북을 나타내는 변수의 값을 갱신하면 끝입니다.
- 슬라이드에 있는 코드는 이 부분을 함수로 만든 코드입니다.

- 사실 클린 코드의 관점에서는 특정 영역에 붙일 수 있는지 확인하는 파트와 실제 붙이는 파트가 서로 다른 함수로 분리되어 있는 것이 바람직하겠지만, 문제의 상황을 그대로 구현하고자 하면 그 둘을 분리할 필요가 없어서 저는 그냥 같은 함수에 뒀습니다.
- 이 부분은 취향 차이라고 생각합니다. 
- 그리고 애초에 이 코드를 따로 함수로 빼내는 대신 main 에 싹 다 때려박아도 되긴 하지만 함수로 빼는 게 구조적으로 예쁩니다.

https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2Fyb3W9%2FbtqFKClaqzj%2FsbTmp5ykJ2Kc9bkquwYSiK%2Fimg.png![image](https://user-images.githubusercontent.com/83942393/143403282-bad029bf-ae9c-4aa1-8057-3647147f1a4a.png)
- 두 번째는 스티커 회전입니다.
- 이런 식으로 이차원 배열에서 회전이나 뒤집기 등을 해야 하는 문제들이 종종 있습니다.
- 몇 번 하다보면 익숙해지지만, 처음 시도해보면 좀 헷갈릴텐데 구현에 조금이나마 도움이 될 만한 팁은 직접 종이에 좌표를 적어두고 돌려보면 도움이 됩니다.

- 지금 이렇게 좌표를 써두고 직접 돌려보면 그다지 어렵지 않게 직사각형의 회전을 구현할 수 있습니다.
- 나중에 배열을 뒤집거나 기타 다른 연산을 직사각형에서 수행하더라도 지금처럼 하면 됩니다.

100
https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FYdlZV%2FbtqFINBb4cZ%2FP1B3rIYcdJS43S0Uthcxv1%2Fimg.png![image](https://user-images.githubusercontent.com/83942393/143403622-bc11a2df-51b2-4ab0-8fa5-de230de3a85e.png)
- 변수 paper를 90도 회전하는 함수는 이와 같이 작성할 수 있습니다.
- paper의 값을 tmp 에 옮겨담았다가 paper[i][j] =  tmp[r-1-j][i]; 옮겨왔습니다.
- 함수를 실행하기 전에 paper의 크기가 r x c 인데 함수를 실행하고 나면 c x r 이 되어야 하니 r 과 c 를 바꿔야 하고, 굳이 t=r; r=c; c=t; 와 같이 직접 구현할 필요 없이 utility 헤더 안에 있는 swap 함수를 이용했습니다. 

https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FbyXTJ1%2FbtqFIiVQ4Kn%2Fdegx2MptNx54434bxmYkMK%2Fimg.png![image](https://user-images.githubusercontent.com/83942393/143403892-650fd6be-0598-4bc4-8397-8bef54b491d7.png)
- 이제 구현만 하면 끝이지만 그 전에 시간복잡도를 한 번 생각해보고 가겠습니다. 
- (노트북 가로 n<=40, 세로 m<=40, 스티커 개수<=100, 스티커 가로 r<=10, 스티커 세로 c<=10)
- 우선 각 스티커에 대해 노트북에 놓을 수 있는지 확인하는 위치는 4 × 40 × 40개입니다. 
- 스티커의 (0, 0)을 4개의 회전 방향 각각에서 노트북의 (0, 0)부터 (N-1, M-1)에 맞춰보기 때문입니다. 
- 물론 엄밀하게는 스티커의 크면 위치의 개수도 줄어들지만 일단은 그냥 느슨하게 계산을 하겠습니다. 

- 그리고 스티커를 특정 위치에 놓을 수 있는지 확인하기 위해 필요한 연산은 스티커의 최대 크기인 10 × 10입니다. 
- 아까 pastable 함수를 보면 알겠지만 2중 for문을 돌며 각 스티커의 칸을 확인해야 하기 때문에 그렇습니다. 
- 마지막으로 스티커는 100개여서 총 연산량은 64000000이고 시간 제한 2초 안에는 충분히 결과가 잘 나옴을 알 수 있습니다. 
- 그리고 지금 이 시간복잡도는 사실 최악에 최악을 상정한 상황입니다. 
- 어떤 스티커를 시작하자마자 바로 붙이는데 성공했다면 그 스티커에 대해 6400 (4 x 40 x 40)개의 위치를 다 볼 필요가 없고, 또 스티커를 특정 위치에 놓을 수 있는지 매번 100칸을 전부 다 보아야 판단 가능한건 아닙니다. 
- 어떨 땐 시작하자마자 1이 겹쳐서 바로 붙일 수 없다는 결과를 받을 수도 있기 때문입니다. 
- 그래서 최악을 상정해도 2초 내로 널널하다는 것을 알고 코딩에 들어가면 되고, 실제로 구현해서 제출해보면 효율적으로 짰을 때 C++ 기준 20ms안에 잘 통과됩니다.

100
https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2F7Gswo%2FbtqFJcnb3J9%2FG4C9ziOG4L06N89425tqf0%2Fimg.png![image](https://user-images.githubusercontent.com/83942393/143404558-530c333d-24d4-4bcb-bfce-f73eadd98cb3.png)

100
https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FbLy9B0%2FbtqFKDdfHKT%2FrG13Ia6ZTGnuBrLStwNIuk%2Fimg.png![image](https://user-images.githubusercontent.com/83942393/143404648-3f77d5c6-8278-4116-bd3f-a2daf609e85b.png)
- 46, 48 번째에 x와 y의 범위가 조금 헷갈릴 수 있는데 삐끗하면 1차이로 오답이 날 수 있으니 이런 인덱스에 심혈을 기울어야 합니다.
- 헷가릴 땐 변수들에 직접 값을 넣어서 생각해보는 것도 도움이 됩니다.
- 예를 들어 n=7이고, r=5 이면 x=0, 1, 2 까지만 스티커를 올려볼 수 있습니다.
- 특히 0-indexed 와 1-indexed를 오가다보면 헷갈리기 쉬워서 아무쪼록 이런 실수로 힘들게 푼 문제를 어처구니 없이 틀리지 않도록 조심해야 합니다. 
- 엄밀히 말해 rot = 3일 때에는 rotate()를 실행하는게 시간 낭비이지만 시간복잡도의 관점에서 큰 차이는 없어서 별도의 처리를 하지는 않았습니다. 

- 세 번째 문제는 BOJ 12100번: 2048 (Easy)입니다. 
- 

