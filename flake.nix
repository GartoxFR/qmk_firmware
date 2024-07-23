{
  description = "PLD Comp";

  inputs = {
      nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";
      systems.url = "github:nix-systems/default-linux";
      flake-utils.url = "github:numtide/flake-utils";

      mini-compile-commands = { url = github:danielbarter/mini_compile_commands; flake = false;};
  };

  outputs = { self, nixpkgs, mini-compile-commands, flake-utils, ... }:
    flake-utils.lib.eachDefaultSystem
      (system:
        let
          pkgs = import nixpkgs {
            inherit system;
          };
          antlr = pkgs.antlr;
        in
        rec {
          devShells.default = pkgs.mkShell
          {
              nativeBuildInputs = with pkgs; [qmk gcc-arm-embedded];

          };
        }
      );
}
