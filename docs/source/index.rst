****************
서문 
****************

.. default-domain:: c

.. |gnulogo| image:: images/A_Slick_GNU_Logo.png 
   :width: 120px


|gnulogo| **과학 계산 라이브러리 사용 설명서**

.. note::

   이 번역 프로젝트는 현재 진행중에 있습니다.

본 서적은 GNU Scientific Library(GSL) 2.7 manual과 관련 자료들을 한글로 번역한 책입니다.
python api를 제공하는 라이브러리(예: :code:`numpy`, :code:`scipy` 등)들은 한글로 된 자료들도 많지만, 
C의 경우 많은 입문서에도 불구하고 과학 계산 라이브러리 쪽에서 한글 자료들이 빈약해 번역을 시작하게 되었습니다.

GSL 2.7 Manual을 기준으로 해서 번역합니다. GSL이 차후 버전으로 갱신될 시 
해당 버전의 변경점들도 같이 번역할 예정입니다.
최대한 한글로 풀어씀을 목적으로 합니다. 


원본 문서가 GNU 자유 문서 사용 허가서(GFDL) 아래에서 베포됨에 따라 
해당 허가서 조항에 의거해 이 번역서의 모든 내용 또한 GFDL을 따릅니다.

일부 로고나 그림은 GFDL이 아닌 퍼블릭 도메인나 GPL 등과 같은 다른 허가 조항을 가진 경우도 있습니다.
이 경우는 따로 기술합니다.


구체적으로 번역자 본인이 사용에 참고하려고 번역하는 책이기에 참고와 사용에 유용한 정보들도 같이 포함합니다.
원본 사용 설명서는 라이브러리의 사용에 필요한 상세한 내용을 전부 기술하고 있지는 않습니다. 
필요에 따라 본래 설명서에 없는 추가적인 정보들을 문장과 단원에 넣을 것 입니다. 
그러한 정보들은 끝에 다음과 같은 기호 '(*)'를 써서 나타낼 것입니다. (*)

.. code-block::

    Additional Contents (*)
    #.# Additional Contents Chapter (*)
        Additional sentence (*). 
   
   footnote: additional information (*)




.. only:: html

   이 번역서의 원문은 `GNU Scientific Library Manual  <https://www.gnu.org/software/gsl/doc/html/index.html>`_  로 보거나, 
   `pdf <https://www.gnu.org/software/gsl/doc/latex/gsl-ref.pdf>`_ 로 다운받을 수도 있습니다. 


.. only:: latex

   이 번역서의 원문인 GSL 2.7 Manual은 다음 사이트에서 확인할 수 있습니다. 

   <https://www.gnu.org/software/gsl/doc/html/index.html>


   다음 사이트 주소에서 해당 문서를 PDF로 다운로드할 수도 있습니다. 

   <https://www.gnu.org/software/gsl/doc/html/index.html>

해당 웹 문서들과 pdf 문서들은 `Sphinx <https://www.sphinx-doc.org/en/master/>`_ 프로그램을 이용해 만들어졌습니다. 
Sphinx를 위한 사용 설명서의 원본 문서들은 :code:`.rst` [#ReS]_ 파일 형식으로 
GSL의 베포 파일 내부 :code:`/doc/` 디렉토리에 예제 코드와 그림 등과 함께 저장되어 있습니다.

.. only:: html

   RST 파일 형식에 관해서 `A ReStructuredText Primer <https://docutils.sourceforge.io/rst.html>`_ 문서를 참고할 수 있습니다.

.. only:: latex

   Sphinx에 관한 자세한 내용은 공식 홈페이지인 https://www.sphinx-doc.org/en/master/ 를 참고할 수 있습니다.
   해당 프로그램에서 쓰는 rst 파일 형식은 https://docutils.sourceforge.io/rst.html 를 참고하길 바랍니다.

.. only:: latex

   본 번역서의 원본은 https://github.com/HYUNSEONG-KIM/GSL_KOR_MANUAL.git 에서 찾을 수 있습니다.
   디지털 문서와 PDF 파일은 Readthedocs 호스팅 서비스를 이용하고 있습니다. 다음 주소로 접근할 수 있습니다.

   https://gsl-kor-manual.readthedocs.io/ko/latest/


문서에서 오류가 발견되거나 번역에 기여하고 싶다면 번역서의 Git 저장소에 branch로 만들어 수정을 하거나 
다음 이메일로 알려주길 바랍니다.

::

   qwqwhsnote@gm.gist.ac.kr


.. toctree::
   :maxdepth: 2
   
   소개
   GSL 설치
   라이브러리 사용
   오류 관리
   수학 함수들
   복소수
   다항식
   특수 함수
   벡터와 행렬
   순열
   BLAS 지원
   고속 푸리에 변환
   담금질 기법
   수치 미분
   함수의 근 탐색
   함수의 최솟값 탐색
   선형 최소 제곱법
   물리 상수
   autoconf
   GSL의 기여자들
   GNU 일반 공중 사용 허가서
   GNU 자유 문서 사용 허가서
   GSL 디자인 문서
   참고 자료
   영문 용어

..
   
   순열
   조합
   중복 집합
   정렬
   BLAS 지원
   선형 대수학
   고유 공간
   고속 푸리에 변환
   수치 적분
   난수 생성
   Quasi-Random Sequences
   난수 분포
   통계
   통계 실행
   통계 창 이동
   디지털 필터링
   히스토그램
   N-튜플
   몬테카를로 적분
   담금질 기법
   상미분 방정식
   보간법
   수치미분
   체비쇼프 근사
   Series Acceleration
   웨이블렛 변환
   이산 한켈 변환
   함수의 근 탐색
   함수의 최솟값 탐색
   다변수 함수의 근 탐색
   다변수 함수의 최솟값 탐색
   선형 최소 제곱법
   비선형 최소 제곱 근사
   B-스플라인
   희소 행렬
   희소 연산의 BLAS 지원
   희소 선형 대수학
   물리 상수
   IEEE 부동 소수 대수
   GSL의 기여자들
   수치 해석 프로그램 디버깅
   Autoconf 매크로
   GSL CBLAS 라이브러리
   C 표준 라이브러리
   GNU 일반 공중 사용 허가서
   GNU 자유 문서 사용 허가서

.. rubric:: 각주

.. [#ReS] ReStructuredText의 약자입니다.
