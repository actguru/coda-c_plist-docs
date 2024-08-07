# bla, bla: TODO

%global sover   1
%global thename libcoda-c_plist
%global libname %{thename}%{sover}

Name:           coda-c_plist
Version:        1.2.3
Release:        0
Summary:        The Coda-C Property List Library
License:        AGPL-3.0
Group:          System/Libraries
URL:            https://github.com/actguru/coda-c_plist
Source:         https://github.com/actguru/coda-c_plist/archive/refs/tags/%{version}.tar.gz
BuildRequires:  gcc

%description
This library provides a classed system of objects that model the Apple Propery List or 'plist'.
A plist is any one of the supported objects where containers reference
supported objects, but is most often a Dictionary.
Plists are easy to create and modify programmatically, and even easier to save and load from disk.

%prep
%setup -q

%build
make

%install
%make_install LIB=%{_lib}

%check
make test

%post -p /sbin/ldconfig
%postun -p /sbin/ldconfig

%files
%doc README.md
%license LICENSE
%{_libdir}/%{thename}.so.*

%package tool
Summary:        The "codalist" Property List Utility
Group:          Productivity/File utilities

%description tool
This program slices and dices plists of various formats,
including JSON and Apple XML plist.
Each argument to this program is an instruction for inspecting, loading,
saving, or altering plists, etc.

%files tool
%license LICENSE
%{_bindir}/codalist
%{_mandir}/man1/codalist.1coda-c*

%package devel
Summary:        Development files for The Coda-C Property List Library
Group:          Development/Libraries/C and C++

%description devel
Development files for The Coda-C Property List Library

%files devel
%{_includedir}/coda-c*.h
%{_libdir}/%{thename}.so

%changelog