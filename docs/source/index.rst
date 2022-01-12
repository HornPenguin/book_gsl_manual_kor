****************
서문 
****************

.. default-domain:: c

.. |gnulogo| image:: _static/A_Slick_GNU_Logo.png 
   :width: 120px


|gnulogo| **과학 계산 라이브러리 사용 설명서**

.. only:: html

   .. note::

      이 번역 프로젝트는 현재 진행중에 있습니다.

본 서적은 GNU Scientific Library(GSL) 2.7 manual과 관련 자료들을 한글로 번역한 책입니다.
python api를 제공하는 라이브러리(예: :code:`numpy`, :code:`scipy` 등)들은 한글로 된 자료들도 많지만, 
C의 경우 많은 입문서에도 불구하고 과학 계산 라이브러리 쪽에서 한글 자료들이 빈약해 번역을 시작하게 되었습니다.

GSL 2.7 Manual을 기준으로 해서 번역합니다. 
GSL이 차후 버전으로 갱신될 시 해당 버전의 변경점들도 같이 번역할 예정입니다.
번역은 최대한 한글로 풀어씀을 목적으로 합니다. 

구체적으로 번역자 본인이 사용에 참고하려고 번역하는 책이기에 참고와 사용에 유용한 정보들도 같이 포함합니다.
원본 사용 설명서는 라이브러리의 사용에 필요한 상세한 내용을 전부 기술하고 있지는 않습니다. 
필요에 따라 본래 설명서에 없는 추가적인 정보들을 문장과 단원에 넣을 것 입니다. 
그러한 정보들은 끝에 다음과 같은 기호 '(*)'를 써서 나타낼 것입니다(*).

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

   https://www.gnu.org/software/gsl/doc/html/index.html


   다음 사이트 주소에서 해당 문서를 PDF로 다운로드할 수도 있습니다. 

   https://www.gnu.org/software/gsl/doc/latex/gsl-ref.pdf

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

.. only:: latex
   
   .. raw:: latex
      
      \newpage

      \begin{center}\Large{\textbf{저작권 고지}}\end{center}


.. only:: html

   **원 영문 원서의 저작권 Copyright of the Original English Version:**

   :: 

      Copyright © 1996-2021 The GSL Team.
      Permission is granted to copy, distribute and/or modify this document under the terms of the
      GNU Free Documentation License, Version 1.3 or any later version published by the Free Software
      Foundation; with the Invariant Sections being “GNU General Public License” and “Free Software
      Needs Free Documentation”, the Front-Cover text being “A GNU Manual”, and with the Back-
      Cover Text being (a) (see below). A copy of the license is included in the section entitled “GNU
      Free Documentation License”.
      (a) The Back-Cover Text is: “You have freedom to copy and modify this GNU Manual, like
      GNU software.”
      Printed copies of this manual can be purchased from Network Theory Ltd at
      http://www.network-theory.co.uk/gsl/manual/.
      The money raised from sales of the manual helps support the development of GSL.

   **번역서의 저작권 Copyright of the Translated Korean Version:**

   :: 

      Copyright © 2022  Hyung Seong, Kim

      Permission is granted to copy, distribute and/or modify this document under 
      the terms of the GNU Free Documentation License, Version 1.3 or any later version 
      published by the Free Software Foundation as same as the original English version of the text (shown above); 
      with additional Invariant Sections "역자와 참고 자료(*)", 
      A copy of the license is included in the section entitled "GNU 자유 문서 사용 허가서". 

      Copyright © 2022  김현성 Hyung Seong, Kim

      GNU 자유 문서 사용 허가서 1.3판과 자유 소프트웨어 재단에서 발행한 이후의 갱신본의
      규정에 따라, 본 저작물의 복제, 베포 및 수정을 허가합니다. 상기한 영어 원서와 똑같은 규약을 
      추가 변경 불가 부분 "역자와 참고 자료(*)" 단원을 포함해 따릅니다.
      이 허가서의 복사본은 "GNU 자유 문서 사용 허가서"로 지어진 단락에
      포함되어 있습니다.

.. only:: latex

   .. topic:: 내용
      
      **원 영문 원서의 저작권 Copyright of the Original English Version**

       Copyright © 1996-2021 The GSL Team.
       Permission is granted to copy, distribute and/or modify this document under the terms of the
       GNU Free Documentation License, Version 1.3 or any later version published by the Free Software
       Foundation; with the Invariant Sections being “GNU General Public License” and “Free Software
       Needs Free Documentation”, the Front-Cover text being “A GNU Manual”, and with the Back-
       Cover Text being (a) (see below). A copy of the license is included in the section entitled “GNU
       Free Documentation License”.
       (a) The Back-Cover Text is: “You have freedom to copy and modify this GNU Manual, like
       GNU software.”
       Printed copies of this manual can be purchased from Network Theory Ltd at
       http://www.network-theory.co.uk/gsl/manual/.
       The money raised from sales of the manual helps support the development of GSL.
      
      **번역서의 저작권 Copyright of the Translated Korean Version**

       Copyright © 2022  김현성 Hyung Seong, Kim

       Permission is granted to copy, distribute and/or modify this document under 
       the terms of the GNU Free Documentation License, Version 1.3 or any later version 
       published by the Free Software Foundation as same as the original English version of the text (shown above); 
       with additional Invariant Sections "역자(*)", 
       A copy of the license is included in the section entitled "GNU 자유 문서 사용 허가서". 
 
       Copyright © 2022  김현성
 
       GNU 자유 문서 사용 허가서 1.3판과 자유 소프트웨어 재단에서 발행한 이후의 갱신본의
       규정에 따라, 본 저작물의 복제, 베포 및 수정을 허가합니다. 상기한 영어 원서와 똑같은 규약을 
       추가 변경 불가 부분 "역자(*)" 단원을 포함해 따릅니다.
       이 허가서의 복사본은 "GNU 자유 문서 사용 허가서"로 지어진 단락에
       포함되어 있습니다.
 
   .. topic:: 표지와 글꼴

      **글꼴**

      ..

         나눔 명조
         나눔 고딕
         나눔 D2 폰트를 사용했습니다.

         Copyright (c) 2010, NAVER Corporation (https://www.navercorp.com/) 
      
      **그림**

      본 커버의 디자인은 여러 저작물의 조합입니다.
      그림 라이센스 조항은 해당 그림들과 함께 본 책의 "그림의 허가서"
      단락에 기재합니다. 이 외 메뉴얼 원본의 그래프등의 그림은 GDFL을 따르고
      외부 디자인을 제외한 커버의 디자인은 GPL 라이센스 아래에 베포됩니다.


.. toctree:: 
   :maxdepth: 2

   소개.rst
   라이브러리 사용.rst
   오류 관리.rst
   수학 함수들.rst
   복소수.rst
   다항식.rst
   특수 함수.rst
   벡터와 행렬.rst
   순열.rst
   조합.rst
   중복 집합.rst
   정렬.rst
   BLAS 지원.rst
   선형 대수학.rst
   고유 공간.rst
   고속 푸리에 변환.rst
   수치 적분.rst
   난수 생성기.rst
   Quasi-연속 난수.rst
   난수 분포.rst
   통계.rst
   통계 실행.rst
   디지털 필터링.rst
   히스토그램.rst
   N-튜플.rst
   몬테카를로 적분.rst
   담금질 기법.rst
   상미분 방정식.rst
   보간법.rst
   수치 미분.rst
   체비쇼프 근사.rst
   급수 가속.rst
   웨이블렛 변환
   이산 한켈 변환.rst
   함수의 근 탐색.rst
   함수의 최솟값 탐색.rst
   다변수 함수의 근 탐색.rst
   다변수 함수의 최솟값 탐색.rst
   선형 최소 제곱법.rst
   비선형 최소 제곱법.rst
   B-스플라인.rst
   희소 행렬.rst
   희소 BLAS 지원.rst
   희소 선형 대수.rst
   물리 상수.rst
   IEEE 부동 소수점 대수.rst

   수치 해석 프로그램의 디버깅.rst
   autoconf.rst
   GSL의 기여자들.rst
   GSL CBLAS 라이브러리.rst
   GNU 일반 공중 사용 허가서.rst
   GNU 자유 문서 사용 허가서.rst
   add_docs/GSL 디자인 문서.rst
   add_docs/이력.rst
   add_docs/GSL 설치.rst
   add_docs/참고 자료.rst
   add_docs/병렬화.rst
   add_docs/영문 용어.rst
   add_docs/역자.rst

.. rubric:: 각주

.. [#ReS] ReStructuredText의 약자입니다.
