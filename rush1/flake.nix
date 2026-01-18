{
  description = "Epitech flakes";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";
    epiclang.url = "github:Sigmapitech/epiclang";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { nixpkgs, flake-utils, ... }:
    flake-utils.lib.eachDefaultSystem (system:
      let pkgs = nixpkgs.legacyPackages.${system}; in
      {
        devShells.default =
          pkgs.mkShell {
            buildInputs = with pkgs; [
              clang
              valgrind
              compiledb
              gcovr
            ];
          };
      });
}
