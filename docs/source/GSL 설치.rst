
**********************************
GSL 설치(*)
**********************************

많은 GNU 프로젝트의 결과물들이 source code 형태로 배포 되고 있습니다. 
어떤 프로젝트들의 경우 release된 설치 파일(.exe, .msi, .deb, .rpm)을 통한 배포도 하고 있지만, 
GSL 라이브러리의 경우는 공식적으로 소스코드를 이용한 베포를 사용하고 있습니다. 

GSL 또한 Windows, Linux, Mac에서 사전 컴파일 된 라이브러리가 존재합니다.
Windows에서는 `Cygwin <http://www.cygwin.com/>`_ 의 일부분으로 존재하고 
Linux 등에서는 각 베포판의 패키지 저장소에 있습니다. 


.. note::

    이러한 사전 컴파일 라이브러리는 공식 베포가 아니라는 점에 유의해야 합니다.

해당 파일을 사용할 수도 있고 소스코드를 실제 컴파일해서 설치할 수도 있습니다.


패키지 설치
=================

Linux
-----------------------

각각 베포판의 저장소에 있는 패키지를 pacakage manager를 이용해 설치하면 됩니다.

**Ubuntu/Min/Debian** 계열: APT package manager

.. code-block:: console
    
    $sudo apt install libgsl-dev

**Fedora/Cent/RHEL** 계열: DNF package manager

.. code-block:: console
    
    $sudo dnf install gsl-devel

Mac
-----------------------

OSX에서는 `Homwbrew <https://brew.sh/index_ko>`_ 를 통해 설치할 수 있습니다.

.. code-block:: console
    
    $brew install gsl

Windows
-----------------------


소스코드 설치
====================
패키지를 사용한 방법은 빠르고 쉽게 설치할 수 있고 버전 관리 측면에서도 많은
유용성이 있지만 한가지 단점은 최신 공식 베포를 빠르게 반영하지는 않는다는 점입니다.

예로 Ubuntu 환경의 예를 들어봅시다. 

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
나중에 다른 GNU 프로젝트들을 사용할 때 되리라 생각합니다.

GSL 다운로드 
-----------------

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

    gsl-lastest.tar.gz


웹 브라우저를 통해 파일을 다운 받을 수 있고 터미널을 이용해 받고 싶다면 
:code:`wget` 나 :code:`curl` 명령어를 사용하면 됩니다.

다음은 :code:`gsl-lastes.tar.gz` 을 다운 받을 수 있는 명령어입니다.

.. code-block:: console

    $wget https://ftp.gnu.org/gnu/gsl/gsl-lastest.tar.gz


GSL 설치(Linux & Mac)
-----------------------

GSL의 설치는 다운로드 받은 압축 파일 내의 :code:`INSTALL` 파일에 잘 기술 되어 있습니다. 
본 내용은 :code:`INSTALL` 파일의 일부를 기술한 것입니다. 추가적인 선택 사항이나 
다른 OS에서의 설치는 :code:`INSTALL` 파일을 참고할 수 있습니다.

본 라이브러리는 표준 GNU 설치 절차(GNU installation procedure)를 따릅니다. 
표준 GNU 설치 절차는 다음의 6가지 단계로 이루어져있습니다.

1. Prerequisites
2. Downnloading the source
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
2. make

이 중 make는 대체 불가능합니다 [#makealt]_ . 
Windows에서도 gcc나 make를 설치할 수는 있습니다.
그러나 많은 프로젝트들이 Configure 파일을 이용합니다.
Configure 파일은 프로젝트별로 작성된 shell 스크립트로 
빌드하는 시스템의 정보를 반영해 최적화 된 Makefile을 만듭니다. 
Windows에서 이러한 shell 스크립트는 batch 파일이 역할을 합니다. 
때문에 기본 CMD나 PowerShell에서는 이 스크립트를 사용할 수 없습니다.
Windows에서는 별도로 호환되는 Shell을 먼저 설치해 주어야합니다.

일반적으로 GNU 프로젝트를 설치할 때에는 GCC(Gnu Compiler Collection)을 기본으로 사용합니다. 
하지만 소개에서 말했다시피 굳이 GCC를 쓸 필요는 없습니다. 
Clang이나 ICC, AOCC [#iccaocc]_ 등의 다른 C 컴파일러를 사용할 수도 있습니다.

여기서는 Linux에서 Ubuntu 환경에서 Bash를 기준으로 설명을 진행합니다. 
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

make도 같이

Ubuntu와 같은 Debian 계열의 기본 저장소에서 이는 :code:`build-essential` 패키지 내에 포함되어 있습니다. 
다음을 입력해 :code:`build-essential`  를 설치하면 필요한 
:code:`gcc` ,``g++`` ,``make`` 등의 여러 컴파일러와 유틸리티를 설치 할 수 있습니다.

::

    List of Build-Essential packages
                    as of 2017-09-17, Debian sid

    이 패키지는 메타 패키지로 다른 여러 패키지의 묶음 패키지입니다.

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

Downloading Source
~~~~~~~~~~~~~~~~~~~~~~

위에서 설명한 FTP 사이트에서 :code:`.tar.gz` 파일을 다운로드하고, 이를 다음의 명령어를 통해 압축을 해제합니다.

.. code-block:: console

    $tar -xvzf gsl-lastest.tar.gz


이제 압축을 해제한 디렉토리로 들어갑시다.

.. code-block:: console

    $cd ./gsl-lastest

 
Configuration
~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: console

    $./configure

를 입력하면 자동으로 시스템 설치 환경을 위한 :code:`Makefile` 을 만들어 냅니다. 
기본 컴파일러의 설정은 컴파일러는 gcc로 되어있습니다.

실행 할때 컴파일러를 별도로 지정해줄 수 있습니다.
이때, 컴파일러마다 주어진 설정 이름이 다를 수 있습니다. 
해당 설정을 별도로 정해주어야 합니다.

clang과 icc에 대해 다음과 같이 설정할 수 있습니다.

./configure CC=clang CPP="clang -E" CFLAGS="-O4" LD="llvm-ld" OTOOL=llvm-ld 
AR=llvm-ar RANLIB=llvm-ranlib NM=llvm-nm MC=llvmc PROF=llvm-prof AS=llvm-as


이 과정은 시간이 조금 걸립니다. 

Windows를 Linuex/Mac과 별개로 서술하는 이유는 이 단계 때문입니다. 해당 파일은 Unix/Linux 시스템에서 사용하는 여러
bash

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


6 단계까지 마무리하면 GSL의 설치는 끝납니다. 기본으로 설치된 위치는 :code:`/usr/local/lib` 입니다. 
이 폴더 안에는 다음과 같은 :code:`.so`  동적 라이브러리가 담겨있습니다. 
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


이 라이브러리를 이용해 프로그램을 작성하기 위해서는 링커가 해당 라이브러리에 접근할 수 있어야 합니다. 때문에 이러한 위치를 링커에게 알려주어야 합니다.

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

**환경 변수에 추가하기**

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

참고 문헌
==============

Windows 에서의 설치

* GNU Official Website: GSL project page https://www.gnu.org/software/gsl/
* Build GSL on Windows Using Native Tools https://www.gnu.org/software/gsl/extras/native_win_builds.html

.. rubri: 각주

.. [#bashrc] 해당 파일은 bash가 시작할 때 실행되는 명령어를 기술하고 있습니다.
.. [#iccaocc] 각각 Intel C/C++ Compiler, AMD Optimized C/C++ Compiler를 의미합니다. 
              GNU/Linux, Mac, Windows 모두 지원합니다. 
              AOCC의 Windows 지원은 베타 버전에 있습니다.
              AOCC는 LLVM/Clang의 포크로 만들어졌습니다.
.. [#makealt] make는 빌드 과정을 편리하게 만드는 도구일 뿐이므로 대체 불가능하다는 어폐가 있는 표현이기는 합니다만, 
              하지만 대규모 프로젝트를 굳이 별도의 빌드 도구로(ninja 같은) 새로 만들거나 손수 따라할 이유가 없습니다.
