{
  description = "A flake exposing a fork of Eleobert's C++ DbScan implmementation";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-25.11";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = {
    nixpkgs,
    flake-utils,
    ...
  }:
    flake-utils.lib.eachSystem
    ["x86_64-linux" "aarch64-linux"]
    (
      system: let
        pkgs = import nixpkgs {
          inherit system;
        };
      in {
        packages.default = pkgs.stdenv.mkDerivation {
          name = "DbScan";
          version = "1.0.0";
          src = ./.;
          nativeBuildInputs = with pkgs; [
            cmake
            ninja
          ];
        };
      }
    );
}
