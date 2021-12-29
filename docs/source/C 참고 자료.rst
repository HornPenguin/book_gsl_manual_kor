*****************
C 참고 자료
*****************



서적
---------------------------

시중에 다양한 C 입문, 학습서들이 나와있지만 표준적으로 쓰이는 C 서적은 두 가지가 있습니다.

하나는 데니스 리치와 브라이언 커니핸이 작성한 책으로 ANSI C 표준을 기반으로한 책입니다. 
이 둘은 C 언어 자체를 개발한 사람들이기도 합니다 [#KR]_ . 

Kernighan, B.W. & Ritchie, D.M., The C Programming Language, 2nd ANSI, Pearson Educación, 1988, isbn:9789688802052.

다른 하나는 K.N.King 의 저서로 C99 표준을 따릅니다.

King, K.N., C Programming: A Modern Approach. 2nd, W.W. Norton, 2008, isbn:9780393979503.



.. index:: ASCII code

ASCII 코드표 [#ASCII]_
----------------------------

ASCII는 정보 교환을 위한 미국 표준 문자표를 의미합니다 [#ASCIICODE]_.
이 코드표는 7-bit 크기의 숫자로 이루어져 있으며, 0-127까지의 숫자에 표기와 제어를 위한 문자가 할당되어 있습니다.

.. math::

    b_7 b_6 b_5 b_4 b_3 b_2 b_1 = print or contorl character

0-31, 127에 제어 문자가 할당되어 있고 나머지는 출력 문자가 할당되어 있습니다.

ASCII 표는 1963년도 처음 표준안이 발표된 이후로 몇몇 개정이 있어왔습니다.
하지만, 1967년도 개정판이 가장 일반적으로 많이 쓰입니다. 다음은 1963, 1965, 1967년도 
발표된 ASCII 표입니다.

DEC: 10진수, HEX: 16진수, OCT: 8진수

.. csv-table:: ASCII Table 1963-1967
    :file: examples/ASCII.csv
    :header-rows: 1





1965년도 개정에서는 알파벳 소문자들이 추가되었고, 일부 문자들의 위치와 제어 문자들의 이름이 바뀌었습니다.

0-31, 127에 할당된 제어 문자들은 프린터 같은 기기를 제어하거나 자기 테이프와 같은 저장 장치에서
값을 읽어올 때 구분을 위한 메타 정보 제공을 위함입니다. 
1963년도 버전과 이후 개정의 차이는 이러한 제어 문자들의 이름들이 통신과 파일 입출력, 교환등을 위한
이름으로 좀 더 직관적이게 바뀌었다는 점입니다. 

.. list-table:: ASCII 제어 문자
    :header-rows: 1

    * - Control CHAR
      - 설명
    * - NUM
      - NUM은 NUM입니다.

확장된 ASCII는 1bit가 추가 된 8bit 기반의 코드로 
128-255 숫자 범위를 추가로 가지며, 
라틴 계열 문자에 대한 지원과 추가적인 선 기호, 
수학 기호 등을 포함합니다.



C 표준
--------------------------

ANSI C 는 미국 국립 표준 협회 [#ANSI]_ 에서 지정한 C 표준을 말합니다. 이는 C89와 동치입니다. 
C89:
C99:
C 11:


표준 수학 라이브러리
-----------------------------




.. rubric:: 각주

.. [#ASCII] Gorn, S., Bemer, R. W., & Green, J. (1963). American standard code for information interchange. Communications of the ACM, 6(8), 422-426.
.. [#ASCIICODE] American Standard Code for Information Interchange, ASCII
.. [#ANSI] Americal National Standards Institute, ANSI
.. [#KR] K&R이나 TCPL(The C Programming Language)로 축약해 부르기도 합니다. 간혹 K&R이 2nd 판이 아닌 1st 판본을 의미하는 경우도 있으니 조심해야합니다.



