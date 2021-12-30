.. _chap_autoconf-macros:

***************
Autoconf Macros
***************

:code:`autoconf` 를 사용하는 응용 프로그램들은 표준 매크로 :code:`AC_CHECK_LIB` 를 사용해  
:code:`configure` 스크립트에서 GSL를 자동으로 링크할 수 있습니다. 라이브러리는 CBLAS와 
수학 라이브러리들에 대해서도 자체적으로 의존하고 있기 때문에 이 의존 라이브러리들을 :code:`libgsl` 을
링크하기 전에 가져오도록 해야합니다. 이를 수행할 수 있는 명령어는 다음과 같습니다.
명령어들은 :file:`configure.ac` 에 작성되어야합니다. 

.. code-block:: 

  AC_CHECK_LIB([m],[cos])
  AC_CHECK_LIB([gslcblas],[cblas_dgemm])
  AC_CHECK_LIB([gsl],[gsl_blas_dgemm])

:code:`libm` 와 :code:`libgslcblas` 를 :code:`libgsl` 이전에 배치시켜야 함을 기억해야합니다.
다른 순서로 배열하면 작동하지 않을 것입니다. 구성(configure) 단계에서 라이브러리를 찾을 수 있다면
다음과 같은 출력을 내보냅니다.

.. code-block:: console

  checking for cos in -lm... yes
  checking for cblas_dgemm in -lgslcblas... yes
  checking for gsl_blas_dgemm in -lgsl... yes

라이브러리를 찾을 수 있다면 검증 프로그램이 
매크로 :code:`HAVE_LIBGSL`, :code:`HAVE_LIBGSLCBLAS`, :code:`HAVE_LIBM` 를 정의하고
변수 :code:`LIBS` 에 :code:`-lgsl -lgslcblas -lm` 옵션들을 추가합니다.

위의 검증 과정은 어느 버전의 라이브러리에서도 사용 가능합니다.
이 과정은 보편적으로 사용할 수 있고, 함수의 버전은 중요하지 않습니다.
파일 내에는 대체 매크로 :file:`gsl.m4` 가 있어 특정 라이브러리의 버전을 검사할 수도 있습니다.
이 매크로를 사용하기 위해서는 위의 검증 과정을 기술하는 명령어들 대신
다음의 명령어들을 :file:`configure.in` 에 추가하면 됩니다.

.. code-block:: console

  AX_PATH_GSL(GSL_VERSION,
             [action-if-found],
             [action-if-not-found])


:macro:`GSL_VERSION` 인자는 :code:`major.minor` 나 :code:`major.minor.micro` 형식의 
2-3 자리 정수 값을 가져야 합니다. 이는 필요한 라이브러리 베포판의 버전 숫자를 가르킵니다.

:code:`action-if-not-found` 에 대해 일반적으로 많이 쓰이는 설정은

.. code-block:: console

  AC_MSG_ERROR(could not find required version of GSL)

:file:`Makefile.am` 파일에 변수 :macro:`GSL_LIBS` 와 :macro:`GSL_CFLAGS` 를 추가해
제대로 된 컴파일러 옵션들을 얻을 수 있습니다. :macro:`GSL_LIBS` 는 :code:`gsl-config --libs` 를
만들고, :macro:`GSL_CFLAGS` 는 :code:`gsl-config --cflags` 를 만들어줍니다. 
예를 들어서

.. code-block:: console

  libfoo_la_LDFLAGS = -lfoo $(GSL_LIBS) -lgslcblas

.. note::

  매크로 :macro:`AX_PATH_GSL` 는 C 컴파일러를 필요로 함을 유의해야 합니다.
  따라서 이 매크로는 :file:`configure.in` 파일 내에 
  매크로 :macro:`AC_LANG_CPLUSPLUS` 전에 기술되어야 합니다.
  이 매크로는 C++로 쓰인 프로그램에 쓰입니다.

:code:`inline` 기능을 검사하기 위해서는 다음의 명령어들을 :file:`configure.in` 에 
작성하고,

.. code-block:: console
  
  AC_C_INLINE

  if test "$ac_cv_c_inline" != no ; then
    AC_DEFINE(HAVE_INLINE,1)
    AC_SUBST(HAVE_INLINE)
  fi

이러면 매크로가 컴파일 옵션에 정의됩니다 아니면 다른 라이브러리 헤더들 
보다 :file:`config.h` 를 먼저 포함하는 형식으로 검사할 수도 있습니다.

다음 :code:`autoconf` 검증 명령어들은 :code:`extern inline` 를 검사합니다.

.. code-block:: console

  dnl Check for "extern inline", using a modified version
  dnl of the test for AC_C_INLINE from acspecific.mt
  dnl
  AC_CACHE_CHECK([for extern inline], ac_cv_c_extern_inline,
  [ac_cv_c_extern_inline=no
  AC_TRY_COMPILE([extern $ac_cv_c_inline double foo(double x);
  extern $ac_cv_c_inline double foo(double x) { return x+1.0; };
  double foo (double x) { return x + 1.0; };], 
  [  foo(1.0)  ],
  [ac_cv_c_extern_inline="yes"])
  ])

  if test "$ac_cv_c_extern_inline" != no ; then
    AC_DEFINE(HAVE_INLINE,1)
    AC_SUBST(HAVE_INLINE)
  fi

:code:`autoconf` 를 사용하면 대체 함수들을 자동으로 적용 되도록 할 수 있습니다. 
예를 들어, BSD 함수 :code:`hypot` 이 사용가능한지 아닌지 확인하기 위해서
작성하는 응용프로그램의 설정파일 :file:`configure.in` 에 다음 명령어를 넣을 수 있습니다.

.. code-block:: console

  AC_CHECK_FUNCS(hypot)

그리고 파일 :file:`config.h.in` 에 다음 매크로를 정의해 줍시다.

.. code-block:: c

  /* Substitute gsl_hypot for missing system hypot */

  #ifndef HAVE_HYPOT
  #define hypot gsl_hypot
  #endif

이 과정을 거치면 응용 프로그램 소스 파일들에서 :code:`#include <config.h>` 를 사용해
:fun`hypot` 를 사용할 수 없는 상황에서 :fun`gsl_hypot` 로 :fun`hypot` 를 대체할 수 있습니다. 

