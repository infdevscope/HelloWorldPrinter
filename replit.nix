
{ pkgs }:

pkgs.stdenv.mkDerivation {
  name = "helloworld-printer";
  src = ./.;
  
  buildPhase = ''
    g++ -c src/helloprinter.cpp -I./include -o helloprinter.o
    ar rcs libhelloprinter.a helloprinter.o
  '';
  
  installPhase = ''
    mkdir -p $out/include $out/lib
    cp include/helloprinter.h $out/include/
    cp libhelloprinter.a $out/lib/
  '';
}
