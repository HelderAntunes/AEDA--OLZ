# AEDA--OLZ
Hey pessoal quando fizerem overloading do operador << não se esqueçam de fazer:
include iostream

Importante também lembrar o cabeçalho desse tipo de função:
std::ostream& operator<<(std::ostream& o, const SomeType& t);
