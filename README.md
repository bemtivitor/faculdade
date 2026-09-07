# Truco

Jogo de Truco desenvolvido em C++ utilizando CMake.

## Requisitos

Para compilar e executar o projeto, você precisa ter:

- CMake
- GCC/G++ (MinGW)
- Make

### CMake

Caso não tenha o CMake instalado, baixe pelo site oficial:

[Download do CMake](https://cmake.org/download/?utm_source=chatgpt.com)

Durante a instalação, certifique-se de adicionar o CMake ao `PATH` quando essa opção estiver disponível.

Para verificar se o CMake está instalado:

```powershell
cmake --version
```

---

### MinGW / GCC

Este projeto utiliza o GCC através do MinGW-w64.

Uma maneira recomendada de instalar o ambiente no Windows é utilizando o **MSYS2**:

[Download do MSYS2](https://www.msys2.org/?utm_source=chatgpt.com)

Após instalar o MSYS2, abra o terminal **MSYS2 UCRT64** e instale o compilador:

```bash
pacman -S mingw-w64-ucrt-x86_64-gcc
```

O MSYS2 utiliza o ambiente UCRT64 como opção recomendada para novos usuários.

Para verificar se o compilador está disponível:

```bash
g++ --version
```

Também é possível verificar o compilador C:

```bash
gcc --version
```

---

## Estrutura do projeto

```text
truco/
├── CMakeLists.txt
├── truco.cpp
│
├── lib/
│   ├── carta.h
│   ├── carta.cpp
│   ├── baralho.h
│   ├── baralho.cpp
│   ├── jogo.h
│   └── jogo.cpp
│
└── build/
```

A pasta `build/` é criada pelo CMake durante a compilação.

---

# Compilando

Abra o terminal na pasta raiz do projeto:

```powershell
cd caminho/para/truco
```

Configure o projeto com CMake:

```powershell
cmake -S . -B build -G "MinGW Makefiles"
```

Depois compile:

```powershell
cmake --build build
```

Após a compilação, o executável estará em:

```text
build/truco.exe
```

---

# Executando

No PowerShell:

```powershell
.\build\truco.exe
```

---

# Desenvolvimento

Depois que o projeto já estiver configurado, não é necessário executar novamente a configuração do CMake a cada alteração.

Basta:

```powershell
cmake --build build
```

E executar:

```powershell
.\build\truco.exe
```

O fluxo normal será:

```text
Alterar código
      ↓
cmake --build build
      ↓
.\build\truco.exe
```

---

# Configuração inicial completa

Caso esteja configurando o projeto pela primeira vez, os comandos são:

```powershell
cmake -S . -B build -G "MinGW Makefiles"
cmake --build build
.\build\truco.exe
```

Depois da primeira configuração, normalmente basta:

```powershell
cmake --build build
.\build\truco.exe
```
