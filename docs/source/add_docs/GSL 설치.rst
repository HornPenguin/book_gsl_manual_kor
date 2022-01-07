
**********************************
GSL 설치(*)
**********************************


이 단원에서는 GSL 라이브러리의 설치에 관해 다룹니다. 
먼저, 라이브러리를 설치한다는 것은 정적이나 공유/동적 라이브러리 파일을 다른 프로그램이나
컴파일 과정에서 사용할 수 있는 환경을 구축하는 행위를 말합니다.
그냥 단순히 베포하고 있는 :code:`.c` :code:`.h` 파일들을 복사해서
프로젝트 디렉토리에 포함시켜도 됩니다. 
하지만 매우 번거롭고, 프로그램이 공유/동적 라이브러리를
사용할 수 없어 실행 파일의 크기가 커집니다. 

이러한 라이브러리의 설치는 소스 코드를 개발환경에서 컴파일해 구성하는 방안과
사전 컴파일된 라이브러리를 설치하는 두가지 방법입니다. 
GSL 라이브러리의 경우는 공식적으로 소스코드를 이용한 베포를 사용하고 있습니다. 

비공식적으로 Windows, Linux, Mac에서 사전 컴파일 된 라이브러리가 존재합니다.
Windows에서는 `Cygwin`_ 의 일부분으로 존재하고 
Linux, Mac 등에서는 각 베포판의 패키지 저장소에 있습니다. 

.. note::

    이러한 사전 컴파일 라이브러리는 공식 베포가 아니라는 점에 유의해야 합니다.

해당 파일을 사용할 수도 있고 소스코드를 실제 컴파일해서 설치할 수도 있습니다.


패키지 설치
=================

Linux&Mac
-----------------------

각각 베포판의 저장소에 있는 패키지를 pacakage manager를 이용해 설치하면 됩니다.

**Ubuntu/Min/Debian** 계열: APT package manager

.. code-block:: console
    
    $sudo apt install libgsl-dev

**Fedora/Cent/RHEL** 계열: DNF package manager

.. code-block:: console
    
    $sudo dnf install gsl-devel

**OSX** : `Homwbrew <https://brew.sh/index_ko>`_ 

.. code-block:: console
    
    $brew install gsl


Windows
-----------------------

Windows에서는 OS 자체적으로 저장소를 활용한 프로그램 설치를 적극적으로 활용하지 않고
사용자가 개별 파일을 알아서 설치하는 방식이 주가 되어 Linux&Mac과 같은 방법을 사용하려면
별도의 관리 프로그램에서 설치를 해야합니다.

`Cygwin`_ 의 사전 컴파일된 라이브러리를 설치하는 형식으로 사용할 수 있습니다. 
아니면 `Nuget <https://www.nuget.org/>`_ 이라는 패키지 관리 프로그램에서 컴파일된 라이브러리를 설치할 수도 있습니다.

.. only:: html

    `Cygwin gsl pacakage <https://cygwin.com/packages/summary/gsl.html>`_

    `Nuget gsl pacakage <https://www.nuget.org/packages/gsl-msvc-x64/>`_

.. only:: latex
    
    * Cygwin gsl pacakage: https://cygwin.com/packages/summary/gsl.html

    * Nuget gsl pacakage: https://www.nuget.org/packages/gsl-msvc-x64/

.. _Cygwin: http://www.cygwin.com/


소스코드 설치
====================
패키지를 사용한 방법은 빠르고 쉽게 설치할 수 있고 버전 관리 측면에서도 많은
유용성이 있지만 한가지 단점은 최신 공식 베포를 빠르게 반영하지는 않는다는 점입니다.

예로 Ubuntu 환경를 들어봅시다. 

:code:`$apt search libgsl` 을 사용해 저장소에서 해당 라이브러리를 검색할 경우, 
다음과 같은 결과를 볼 수 있습니다. (06-29-2021 확인)


.. code-block:: console

    libgsl-dbg/focal 2.5+dfsg-6build1 amd64
    GNU Scientific Library (GSL) -- debug symbols package

    libgsl-dev/focal 2.5+dfsg-6build1 amd64
    GNU Scientific Library (GSL) -- development package

    libgsl23/focal 2.5+dfsg-6build1 amd64
    GNU Scientific Library (GSL) -- library package

    libgslcblas0/focal 2.5+dfsg-6build1 amd64
    GNU Scientific Library (GSL) -- blas library package

    libocamlgsl-ocaml/focal 1.19.1-2build3 amd64
    GNU scientific library for OCaml

    libocamlgsl-ocaml-dev/focal 1.19.1-2build3 amd64
    GNU scientific library for OCaml

현 시점에서 최신 베포 버전은 :code:`2.7` 입니다. 
이렇듯 사전 컴파일된 라이브러리는 최신 버전을 충실히 반영하지 못합니다. 
때문에 최신 버전의 기능들을 활용하고 싶다면 
소스코드를 이용한 설치 방법을 알아두어야 할 필요가 있습니다.

상기한 설치파일을 제공하지 않는 프로젝트들도 존재하는 만큼 이러한 설치 방법을 알아두면, 
나중에 다른 GNU 프로젝트들을 사용할 때 유용하리라 생각합니다.

소스 코드를 컴파일해 환경을 구성하는 과정은 크게 2가지로 나뉩니다.

1. 소스 코드를 컴파일해 라이브러리 파일 생성 

     Linux/Mac : :code:`.a` , :code:`.la` , :code:`.so`
    
     Windows: :code:`.lib` , :code:`.dll`

2. 컴파일러와 링크 프로그램의 검색 경로에 해당 파일들의 경로 등록 

     Linux, Mac, Windows 모두 컴파일러와 링커에 라이브러리가 있는
     폴더의 정보를 주어야 합니다. 공유/동적 라이브러리를 사용하는 프로그램은
     시스템 PATH 등에 라이브러리 검색 경로를 입력해 주어야 합니다.
     여기서는 Linux의 경우를 주로 설명합니다.
     Windows의 경우 `Microsoft Tech Document-동적 연결 라이브러리 검색 순서`_ 를
     참고해 볼 수 있습니다.

.. _Microsoft Tech Document-동적 연결 라이브러리 검색 순서: https://docs.microsoft.com/ko-kr/windows/win32/dlls/dynamic-link-library-search-order

GSL 설치(Linux & Mac)
-----------------------

GSL의 설치는 다운로드 받은 압축 파일 내의 :code:`INSTALL` 파일에 잘 기술 되어 있습니다. 

본 라이브러리는 표준 GNU 설치 절차(GNU installation procedure)를 따릅니다. 
표준 GNU 설치 절차는 다음의 6가지 단계로 이루어져있습니다.

1. Prerequisites
2. Downloading the source
3. Configuration
4. Building
5. Testing(optional)
6. Final install

Prerequisites
~~~~~~~~~~~~~~~~~~~~~~

소스코드를 이용한 설치에서는 Linux 계열의 구분(Debian, Fedora 등)이나 Mac과 차이가 없습니다.
해당 OS들 모두 GNU 프로젝트의 빌드 과정에서 필요한 사전 패키지들을 모두 활용할 수 있기 때문입니다.

소스코드 형태의 프로젝트를 설치하기 위해서는 
소스코드들을 컴파일 할 수 있는 컴파일러가 필요하고 컴파일 된 파일들을 이용해
실제 사용가능한 형태로 구성하는 빌드 시스템이 필요합니다. 
대부분의 GNU 프로젝트는 Makefile 을 이용해 프로젝트를 구성합니다.

따라서 소스 코드 설치전 다음 두 가지를 사용할수 있는지 확인해야 합니다.

1. 컴파일러
2. `make <https://www.gnu.org/software/make/>`_


일반적으로 GNU 프로젝트를 설치할 때에는 GCC(Gnu Compiler Collection)을 기본으로 사용합니다. 
굳이 GCC를 쓸 필요는 없습니다. 이 라이브러리는 ANSI C를 지원하는 모든 시스템과 컴파일러에서 사용가능하기 때문입니다. 
Clang이나 ICC, AOCC [#iccaocc]_ 등의 다른 C 컴파일러를 사용할 수도 있습니다.

여기서는 GNU/Linux 중 Ubuntu 환경에서 Bash를 기준으로 설명을 진행합니다. 
Fedora 계열과 Mac은 별도로 같이 기술합니다.

컴파일러 설치
^^^^^^^^^^^^^^^^^^^^^^^

다음을 터미널 창에 입력하면 :code:`gcc` 의 설치 유무를 알 수 있습니다.

.. code-block:: console

    $gcc
 
만약, :code:`gcc`  가 설치되어있다면, 
 
.. code-block:: console

    gcc fatal error: no input files
    compliation terminated


의 메세지가 뜰 것입니다. 

.. code-block:: console

    $gcc -v


를 입력하면 설치된 :code:`gcc` 의 버전을 확인 할 수 있습니다. 일반적으로 최신 버전의 프로그램 사용이 권장되므로 
다음을 입력해 :code:`gcc` 의 업그레이드 버전이 있는지 확인하고 이를 업데이트 합니다.

**Ubuntu/Debian**

.. code-block:: console

    $sudo apt update
    $sudo apt upgrade

**Fedora/RHEL**

.. code-block:: console

    $dnf
    $dnf

만약 설치되어있지 않다면, :code:`gcc` 를 설치해 주어야합니다. 
후술할 :code:`build-essential` 을 이용해 다른 개발 도구들과 함께 한꺼번에 설치해도 됩니다.


Ubuntu와 같은 Debian 계열의 기본 저장소에서 이는 :code:`build-essential` 패키지 내에 포함되어 있습니다. 
이 패키지는 메타 패키지의 일종으로 다른 여러 패키지의 묶어서 한번에 설치하기 위한 패키지입니다.

다음을 입력해 :code:`build-essential`  를 설치하면 필요한 
:code:`gcc` , :code:`g++` , :code:`make` 등의 여러 컴파일러와 유틸리티를 설치 할 수 있습니다.

**build-essential** 패키지

.. list-table:: build-essential 패키지의 포함 목록 []
    :header-rows: 1

    * - Package 
      - Description
    * - libc-dev
      - 표준 ISO C 라이브러리
    * - gcc, g++
      - gnu complier collection 과 gnu C++ Compiler
    * - make
      - make 

::

    List of Build-Essential packages
                    as of 2017-09-17, Debian sid

    .

    libc6-dev [!alpha !ia64 !hurd-i386] | libc0.3-dev [hurd-i386] | libc6.1-dev [alpha ia64] | libc-dev
    Provides the ISO C standard library
    Indirectly depended on by g++, but we'll ignore
    it since libc6-dev is used for non-C++ programs too.

    libc6-dev-sparc64 [sparc]
    Used only on the sparc architecture.

    gcc (>= 4:10.2)
    g++ (>= 4:10.2)

    NOTE:
    The libstdc++ -dev library is not needed, as g++ depends on it

    make
    Also depended on by dpkg-dev, but make does warrant its own
    dependency since debian/rules will need it even if dpkg-dev
    stopped depending on it

    dpkg-dev (>= 1.17.11)
    Provides dpkg-genchanges and other scripts.  Versioned, because
    of support for the build-time dependency fields in /debian/control
    and dpkg-architecture support for OS and CPU information.

    NOTE:
    Although this list does not contain them, all `Essential: yes'
    packages are build-essential as well.  A list of such packages
    can be found by executing the following command
        `grep-status -FEssential -sPackage -ni yes'
    when the `grep-dctrl' package is installed and in its default
    configuration.  Such list is installed with this package as
    the file
        `/usr/share/doc/build-essential/essential-packages-list'
    
    hurd-dev [hurd-i386]
    Provides libpthread.so (and other such essential components).


다음을 입력해 :code:`build-essential` 패키지를 설치합니다.

.. code-block:: console

    $sudo apt update
    $sudo apt install build-essential

Fedora/RHEL 계열에서 비슷한 역할을 하는 패키지 묶음으로는 
"Development Tools"와 "Development Libraries"가 있습니다. 

.. code-block:: console

    $sudo dnf groupinstall "Development Tools" "Development Libraries"

GSL 다운로드 
~~~~~~~~~~~~~~~~~~~~~~

GSL은 `Main GNU FTP site <ftp://ftp.gnu.org/gnu/gsl/>`_ 나 가까운 
`GNU mirror site <http://ftpmirror.gnu.org/gsl/>`_  에서 소스코드를 내려받을 수 있습니다.

현재 가장 최신버전은 2021년 6월 1일에 배포된 :code:`gsl-2.7` 버전 입니다. 
가장 최신 버전의 라이브러리를 다운로드 하고 싶다면, 
다음과 같이 위의 ftp 링크에서 가장 최신 버전의 파일을 내려받거나.

.. code-block:: console

    gsl-X.Y.tar.gz
    gsl-X.Y.tar.gz.sig

자동으로 최신 버전으로 업데이트 되는 파일을 내려받을 수도 있습니다.

.. code-block:: console

    gsl-latest.tar.gz


웹 브라우저를 통해 파일을 내려 받을 수 있고 터미널을 이용해 받고 싶다면 
:code:`wget` 나 :code:`curl` 명령어를 사용하면 됩니다.

다음은 :code:`gsl-lastes.tar.gz` 을 다운 받을 수 있는 명령어입니다.

.. code-block:: console

    $wget https://ftp.gnu.org/gnu/gsl/gsl-latest.tar.gz
    $curl curl https://ftp.gnu.org/gnu/gsl/gsl-latest.tar.gz --output gsl_latest.tar.gz

Windows 에서는 :code:`wget` 을 Unix 계열의 :code:`wget` 을 쓰지 않고 자체 기능인 :code:`Invoke-WebRequest` 의 별칭으로
정의했기 때문에 :code:`curl` 과 같이 저장할 파일의 이름을 지정해 주어야 파일을 저장합니다.

.. code-block:: console
    
    >wget https://ftp.gnu.org/gnu/gsl/gsl-latest.tar.gz -O gsl_latest.tar.gz

위에서 설명한 FTP 사이트에서 :code:`.tar.gz` 파일을 다운로드하고, 이를 다음의 명령어를 통해 압축을 해제합니다.

.. code-block:: console

    $tar -xvzf gsl-latest.tar.gz


이제 압축을 해제한 디렉토리로 들어갑시다.

.. code-block:: console

    $cd ./gsl-latest

 
Configuration
~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: console

    $./configure

를 입력하면 자동으로 시스템 설치 환경을 위한 :code:`Makefile` 을 만들어 냅니다. 
이 과정은 시간이 조금 걸립니다. 주어진 시스템과 컴파일러의 기능 지원 여부를 확인해
환경에 맞춘 Makefile을 구성하기 때문입니다.

상황에 따라 사용자 환경에 의존하는 변수들을 담은 
:code:`.h` 확장자의 헤더 파일을 추가로 생성할 수도 있습니다.

모든 작업이 끝나면 :code:`config.status` 파일을 생성합니다.
이 파일은 shell 스크립트로 차후에 현재 빌드 환경과 같은 
설정으로 프로젝트를 빌드할 수 있습니다.

기본 컴파일러는 gcc로 되어있습니다.

실행 할때 컴파일러를 별도로 지정해줄 수 있습니다.
이때, 컴파일러마다 주어진 설정 이름이 다를 수 있습니다. 
해당 설정을 별도로 정해주어야 합니다.

clang과 icc등과 같이 다른 컴파일러를 사용한다면 별도로
이를 configure 스크립트에 변수로 넣어주어야 합니다.

예로 clang을 이용하면 다음과 같이 넣어줄 수 있습니다.

.. code-block:: console

    $./configure CC=clang CPP="clang -E" CFLAGS="-O3" LD="llvm-ld" OTOOL=llvm-ld AR=llvm-ar RANLIB=llvm-ranlib NM=llvm-nm MC=llvmc PROF=llvm-prof AS=llvm-as

:macro:`CC`  , :macro:`CPP` 는 실행 가능한 C, C++ 컴파일러의 이름을 말합니다.

더 자세한 정보는 라이브러리 베포 파일내의 

Windows를 Linuex/Mac과 별개로 서술하는 이유는 이 단계 때문입니다. 
해당 파일은  Shell-script를 사용하기 때문에 Windows CMD나 PowerShell에서 사용할 수 없습니다.

Building & Test
~~~~~~~~~~~~~~~~~~~~~~

:code:`config` 작업이 끝나면 만들어진 :code:`Makefile` 을 이용해 소스코드를 컴파일 합니다. 
:code:`build-essential` 에 포함된 :code:`make` 유틸리티가 이 작업을 해줍니다. 다음을 입력합시다.

.. code-block:: console

    $make

선택사항으로 :code:`make check` 라는 명령어로 패키지에 제공된 자가 검증을 진행할 수도 있습니다. 
(일반적으로 방금 컴파일 과정을 거처 생성된, 미설치된 이진 코드를 사용합니다.)

Final install
~~~~~~~~~~~~~~~~~~~~~~
 
:code:`make` 작업이 끝났으면 다음을 입력해 이를 설치합니다.

.. code-block:: console

    $sudo make install


Configre - Final Install 단계를 한번에 진행하도록 할 수도 있습니다.

.. code-block:: console

    $./configure && make && make install

프로그래밍 환경 구성
~~~~~~~~~~~~~~~~~~~~~~~~~

6 단계까지 마무리하면 GSL의 설치는 끝납니다. 기본으로 설치된 위치는 :code:`/usr/local/lib` 입니다. 
이 폴더 안에는 다음과 같이 :code:`.a` 와 :code:`.so` 확장자로 정적/동적 라이브러리가 담겨있습니다. 
컴퓨터 환경에 따라 해당 디렉토리에 담겨있는 라이브러리는 다양할 수 있습니다.

.. code-block:: console

    User@COMPUTERNNAME:~$ls -l /usr/local/lib
    total 47072
    -rw-r--r-- 1 root root  28142836 Jul  5 22:43 libgsl.a
    -rwxr-xr-x 1 root root       917 Jul  5 22:43 libgsl.la
    lrwxrwxrwx 1 root root        16 Jul  5 22:43 libgsl.so -> libgsl.so.25.1.0
    lrwxrwxrwx 1 root root        16 Jul  5 22:43 libgsl.so.25 -> libgsl.so.25.1.0
    -rwxr-xr-x 1 root root  16451032 Jul  5 22:43 libgsl.so.25.1.0
    -rw-r--r-- 1 root root   2255578 Jul  5 22:43 libgslcblas.a
    -rwxr-xr-x 1 root root       948 Jul  5 22:43 libgslcblas.la
    lrwxrwxrwx 1 root root        20 Jul  5 22:43 libgslcblas.so -> libgslcblas.so.0.0.0
    lrwxrwxrwx 1 root root        20 Jul  5 22:43 libgslcblas.so.0 -> libgslcblas.so.0.0.0
    -rwxr-xr-x 1 root root   1330608 Jul  5 22:43 libgslcblas.so.0.0.0
    drwxr-xr-x 2 root root      4096 Jul  5 22:43 pkgconfig


이 라이브러리를 이용해 프로그램을 작성하기 위해서는 링커가 해당 라이브러리에 접근할 수 있어야 합니다. 
때문에 이러한 위치를 링커에게 알려주어야 합니다.

먼저, :code:`sudo ldconfig -v` 를 입력해 :code:`/usr/local/lib` 가 있는지 확인합니다. 
해당 파일이 없다면, 별도의 설정이 필요합니다. 다양한 방법이 존재합니다.

* 실행 중, 환경 변수 :code:`LD_LIBRARY_PATH` 에 :code:`LIBDIR`  추가하기
* 링크 과정에서 환경 변수 :code:`LD_RUN_PATH` 에 :code:`LIBDIR`  추가하기
* :code:`-Wl, -rpath -Wl, LIBDIR`  옵션을 링크에 넣기
* 관리자 권한을 얻은 후 :code:`/etc/ld.so.conf/`  디렉토리에 :code:`LIBDIR` 이 있는 파일 추가하기

마지막 방법은 :code:`libc.conf` 을 만들어 주면 됩니다. 파일이름은 중요하지 않습니다. :code:`.conf` 파일은 1 줄에 각각 
:code:`.so`  동적 라이브러리 파일들이 있는 디렉토리 경로를 작성하면 됩니다. 
일반적으로 이 방법이 권장됩니다. 
최신 Ubuntu에서는 기본으로 :code:`libc.conf`  파일이 :code:`/etc/ld.so.conf/`  디렉토리에 있어 별도의 설정없이 
설치 후 라이브러리를  바로 활용 가능합니다. :code:`libc.conf`  파일의 내용은 다음과 같습니다.

.. code-block:: console

    # libc default configuration
    /usr/local/lib

* 환경 변수에 추가하기

    :code:`bash` 창에 다음을 입력하면 환경 변수 :code:`LD_LIBRARY_PATH` 에 위치를 추가할 수 있습니다. 

    .. code-block:: console

        LD_LIBRARY_PATH=${LD_LIBRARY_PARH}:/usr/local/lib
        export LD_LIBRARY_PATH 


    그러나 이 방법은 새로운 :code:`bash` 창을 열 때마다 별도로 입력해 주어야합니다. 
    때문에, 계정의 홈 디렉토리에 있는 :code:`.bashrc` 파일의 끝에 다음의 문구를 추가해줍니다 [#bashrc]_ .


    .. code-block:: console

        LD_LIBRARY_PATH=${LD_LIBRARY_PARH}:/usr/local/lib
        export LD_LIBRARY_PATH 


    재부팅 후나 :code:`$source ~/.bashrc` 를 입력하면 정상적으로 사용이 가능합니다.

Windows
==================

Windows 에서의 설치는 복잡합니다. 사실 1가지로 제약하면 의외로 쉽게 해결할 수 있는데 
(VS studio 에서만 사용, Mingw에서만 사용 등과 같이) 설치된 모든 컴파일러에서 사용가능하게
구현하려면 결국은 소스코드를 컴파일해서 Windows의 정적/동적 라이브러리 파일을 만들어야합니다.
gcc 자체가 크로스 컴파일을 지원하므로 Linux에서 Windows 라이브러리 파일을 만드는게 가능합니다.

근래에 나온 Windows Subsystem for Linux(`WSL <https://docs.microsoft.com/ko-kr/windows/wsl/about>`_ )를 사용하면
굳이 Windows에서 사용할 목적으로 GSL을 설치하지 않고 Windows 내의 Linux 환경에서 개발을 할 수도 있습니다.

하지만 Windows에서 사용할 어플리케이션에 과학계산이 필요할 때 GSL을 사용해서 직접 프로그램을 짜고 싶을 수도 있습니다.
이 단원은 그러한 사용자들을 위한 단원으로 Windows에서 직접 Source 파일을 컴파일해 정적/동적 라이브러리 파일을
만드는 예제를 보일 것입니다. GNU 공식 웹사이트에서는 Visual Studio 나 Cmake를 이용한 방법에 대해 소개하고 있습니다.

`Building GSL on Windows Using Native Tools <https://www.gnu.org/software/gsl/extras/native_win_builds.html>`_

Prerequisites에서 필요한 컴파일러, make 도구는 Windows에서도 설치가 가능합니다. 가장 큰 문제는
시스템을 검사해 실제 설치에 사용할 Makefile을 만드는 :code:`configure` 파일이 Shell-script이기 때문에
Windows의 CMD나 Powershell에서 사용할 수 없다는 점입니다. 

때문에 bash 환경 설치가 필요합니다. 다양한 방법이 있지만 (`Gitbash <https://git-scm.com/downloads>`_ 를 사용할 수도 있습니다)
MinGw와 make까지 한번에 설치 가능한 방법을 사용하도록 합시다. 
이 문서에서는 `MSYS2 <https://www.msys2.org/>`_ 를 사용할 것입니다.
MSYS2는 Windows Native 프로그램을 개발할 수 있게 해주는 도구 모음입니다.
홈페이지에서 https://www.msys2.org/ 설치 파일을 내려받아 MSYS2를 설치합니다.

.. warning::

    MSYS2를 사용할 때 사용자 이름에 ASCII 코드내 문자열만을 가지고 공백이 없어야합니다. 
    만약, 사용자 이름이 이 제약을 따르지 않는다면 컴파일, 빌드 과정에서 오류가 발생할 수 있습니다.

MSYS2는 총 6개의 하위 시스템을 가집니다.
기본 설치 위치는 :code:`C:\mysy64` 로 이 안에 다음 6개의 하위 시스템이 있습니다.
크게 2개의 Tool-chain을 제공합니다. GCC와 LLVM/Clang입니다.

.. list-table:: MSYS2 Subsystems
    :header-rows: 1

    * - Subsystem
      - Architecture
      - Description
    * - MSYS
      - x86_64
      - Main
    * - MINGW64
      - x86_64
      - Main
    * - MINGW32
      - i686
      - Main
    * - UCRT64
      - x86_64
      - Main
    * - CLANG64
      - x86_64
      - Main
    * - CLANG32
      - i686
      - Main

첫 실행시 먼저 패키지 데이터 베이스와 시스템을 업데이트 해야합니다. 
다음을 입력합시다. 

.. note::
    
    WSYS2에서는 `pacman <https://wiki.archlinux.org/title/pacman>`_ 이라는 패키지 관리자를 사용합니다.
    이 관리자는 `Arch Linux <https://archlinux.org/>`_ 의 패키지 관리자이기도 합니다.

.. code-block:: console

    $pacman -Syu

갱신을 위해서는 MYSY2의 재실행이 필요합니다. 
재실행 후 다음을 입력해 패키지와 시스템 갱신을 완료합니다.

.. code-block:: console

    $pacman -Su

base-devel에 make가 포함되어 있습니다. 
GCC 나 Clang tool-chain을 설치하고 싶다면 각각 base-devel과 함께
다음의 명령어로 한꺼번에 설치할 수 있습니다.

.. code-block:: console

    $pacman -S --needed base-devel mingw-w64-x86_64-toolchain #GCC
    $pacman -S --needed base-devel mingw-w64-clang-x86_64-toolchain #LLVM/Clang

이제 라이브러리를 빌드하기 위한 준비과정은 끝났습니다. 
GCC를 선택했다면, MSYS2 MinGW x64를 
Clang을 설치했다면 MSYS2 MinGW Clang x64를 열고 리눅스, Mac에서의 빌드 과정을
그대로 따라하면 됩니다. 이때, 각각의 tool-chain은 :code:`C:\mysy64` 아래의 독립된 디렉토리
:code:`mingw64` 와 :code:`clang64` 에서 각각 관리됩니다.

컴파일된 파일들이 각각 빌드 환경; :code:`mingw64` , :code:`clang64` 내의 :code:`bin, lib, include` 에 존재합니다.

::

    \mysy
        └Build Environment
            └bin
            └lib
            └include

이 단계에서 Windows IDE에 MYSY의 MinGW, LLVM/Clang을 컴파일러로 사용해
바로 GSL 라이브러리를 사용하는 환경으로 컴파일할 수 있습니다. 
해당 컴파일러의 :code:`bin, lib, include` 디렉토리에 컴파일 된 GSL 정적/동적 라이브러리들과 헤더 파일들이
들어있기 때문입니다.

이 과정을 통해 나온 라이브러리 파일들은 :code:`.dll` , :code:`.dll.a` , :code:`.a` , :code:`.la` 파일들입니다. 
해당 컴파일러들이 아닌 Windows 내의 다른 컴파일러 예를 들어 MSVS 등에서 사용하려면
:code:`.dll` 파일외에 :code:`.lib` 파일들이 필요합니다. 

:code:`.lib` 는 Windows에서 사용하는 정적 라이브러리 파일 포멧입니다.
:code:`.a` 는 Unix 계열에서 사용하는 정적 라이브러리 파일 포멧으로 디버그 관련 정보에 차이가 있기 때문에
단순히 확장자를 바꾸는 형식으로 사용할 수는 없습니다.

가능한 방안은 라이브러리 관리툴을 사용해 :code:`.dll` 에서 정적 라이브러리 파일을 새로 생성하는 것입니다.
이 과정은 다음 두가지 과정을 거칩니다. 

1. :code:`.dll` 파일에서 :code:`.def` 파일 생성
2. :code:`.def` 파일에서 :code:`.lib` 파일 생성

MSVS [#MSVS]_ 를 사용해 개발하고자 한다면 MSVS 도구를 사용하는 게 간편합니다.
MSVS를 사용하지 않아도, 빌드를 위해 설치한 Tool-chain에서 관련 도구들을 제공합니다.

.. warning::

    이 라이브러리는 :code:`autoconf` 를 사용해 라이브러리의 컴파일 과정에서 시스템과
    컴파일러에 의존하는 몇몇 최적화를 수행하기도 합니다. MinGW와 Clang을 그대로 사용하면
    상관없겠지만, 이렇게 MSVC와 같은 다른 컴파일러 환경으로 라이브러리를 옿긴다면 해당
    사항을 인지하고 있어야 합니다.

def 파일 생성
--------------------

GCC: gendef, dlltool

LLVM/Clang: llvm-dlltool

MSVC [#MSVC]_ :

lib 파일 생성
-------------------
 
디렉토리 내부에
MinGW:

 * gendef 유틸로 dll -> def 생성
 * dlltool or llvm-dlltool 로 def -> lib 파일 생성

Clang과 GCC를 IDE에서 컴파일러로 설치하고 링크 설정을 완료해 사용하면 됩니다.
만약, MSVC를 사용하고자 한다면 추가 작업이 필요합니다.

def -> lib
~~~~~~~~~~~~~~~~~~~

몇가지 선택 사항이 있습니다.

dlltool
^^^^^^^^^^^^^^^^

GNU binary 도구에 포함된 Dill 관리 도구 입니다.




llvm-dlltool
^^^^^^^^^^^^^^^^

LLVM/Clang 도구 모움에 포함된 dll 관리 도구 입니다.

LIB
^^^^^^^^^^^^^^^^

Visual Studio의 라이브러리 관리 도구입니다. 이를 사용하려면 Visual Studio의 개발자 터미널 내에서 사용해야 합니다.
일반 CMD에서도 사용이 불가능하지는 않지만 몇가지 설정을 변경해야합니다.

.. _common_library_document:

참고 문헌
==============

라이브러리에 관한 자세한 내용은 다음 문헌을 추천합니다.
정적(static), 공유(shared), 그리고 동적(Dynamic) 라이브러리에 관한 
내용을 참고할 수 있습니다.

* David A. Wheeler, Program Library HOWTO, version 1.20, 11 April 2003, URL:https://tldp.org/HOWTO/Program-Library-HOWTO/index.html, Checked: 3.Janurary.2022. 

GSL 설치 과정에서 configure 스크립트의 여러 설정 사항들은 다음을 참고할 수 있습니다.

* 베포 라이브러리 파일 내의 :code:`INSTALL` 파일
* configure 설명 :code:`./configure -h` 로 볼 수 있습니다.

이 문서에서 설명한 도구들의 공식 사용 설명서들을 첨부합니다.

.. only:: html

    * `Bash <https://www.gnu.org/savannah-checkouts/gnu/bash/manual/bash.html>`_
    * `GNU/Make <https://www.gnu.org/software/make/manual/make.html>`_
    * `GNU/GCC <https://gcc.gnu.org/onlinedocs/>`_
    * `LLVM/Clang <https://clang.llvm.org/docs/index.html>`_
    * `Visual Studio and MSVC <https://docs.microsoft.com/ko-kr/visualstudio/windows/?view=vs-2022>`_

.. only:: latex

    * Bash 
         https://www.gnu.org/savannah-checkouts/gnu/bash/manual/bash.html
    * GNU/Make 
         https://www.gnu.org/software/make/manual/make.html
    * GNU/GCC 
         https://gcc.gnu.org/onlinedocs/
    * LLVM/Clang 
         https://clang.llvm.org/docs/index.html
    * Visual Studio and MSVC 
         https://docs.microsoft.com/ko-kr/visualstudio/windows/?view=vs-2022

Windows 에서의 설치에 사용한 도구들과 관련 내용은 다음을 참고할 수 있습니다.

.. only:: html

    * `Build GSL on Windows Using Native Tools: MSVC <https://www.gnu.org/software/gsl/extras/native_win_builds.html>`_
    * `How to compile GSL for Windows <https://titanwolf.org/Network/Articles/Article?AID=02d574bd-a867-4ebf-acab-34baf0146445>`_
    * `GNU Binary Utils Manual- dlltool <https://sourceware.org/binutils/docs/binutils/dlltool.html>`_
    * `Microsoft technical documentation, Additional MSVC build tools - LIB Reference <https://docs.microsoft.com/en-us/cpp/build/reference/lib-reference?view=msvc-170>`_

.. only:: latex
    
    * Build GSL on Windows Using Native Tools: MSVC
         https://www.gnu.org/software/gsl/extras/native_win_builds.html
    * How to compile GSL for Windows
         https://titanwolf.org/Network/Articles/Article?AID=02d574bd-a867-4ebf-acab-34baf0146445
    * GNU Binary Utils Manual- dlltool
         https://sourceware.org/binutils/docs/binutils/dlltool.html
    * Microsoft technical documentation, Additional MSVC build tools - LIB Reference
         https://docs.microsoft.com/en-us/cpp/build/reference/lib-reference?view=msvc-170


.. rubri: 각주

.. [#MSVS] Microsoft Visual Studio
.. [#MSVC] Microsoft Visual C++: Microsofot 사의 MSVC는 C++ 컴파일러로 지원하는 C 표준은 
           `Microsoft C/C++ 언어 규칙 | Microsoft Docs`_
           를 참고할 수 있습니다.
.. [#bashrc] 해당 파일은 bash가 시작할 때 실행되는 명령어를 기술하고 있습니다.
.. [#iccaocc] 각각 Intel C/C++ Compiler, AMD Optimized C/C++ Compiler를 의미합니다. 
              GNU/Linux, Mac, Windows 모두 지원합니다. 
              AOCC의 Windows 지원은 베타 버전에 있습니다.
              AOCC는 LLVM/Clang의 포크로 만들어졌습니다.
.. [#makealt] make는 빌드 과정을 편리하게 만드는 도구일 뿐이므로 대체 불가능하다는 어폐가 있는 표현이기는 합니다만, 
              하지만 대규모 프로젝트를 굳이 별도의 빌드 도구로(ninja 같은) 새로 만들거나 손수 따라할 이유가 없습니다.

.. _Microsoft C/C++ 언어 규칙 | Microsoft Docs: https://docs.microsoft.com/ko-kr/cpp/overview/visual-cpp-language-conformance