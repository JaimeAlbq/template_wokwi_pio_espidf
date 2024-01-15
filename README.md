# Porject Template for Wokwi, PlatformIO and ESP-IDF
This is a template for a project using PlatformIO and Wokwi using ESP-IDF framework with CI.

## About
This repository has all features from PlatformIO and Wokwi, so you can have the complete environment of PlatformIO and the simulation of Wokwi and test everything using the GitHub Actions.

## How to use it?
Simple steps to use this template to your project:

1. Clone this repository and copy everything but the `.git` to your new project directory
1. Update the following files to your own needs:
    1. [`platformio.ini`](platformio.ini) = here you set all your PlatformIO environment
    1. [`wokwi.toml`](wokwi.toml) = update accordinly to your board name just replacing the `esp32dev` one
    1. [`diagram.json`](diagram.json) = you can download/copy from the web version of Wokwi to here
    1. [`test/wokwi/template.test.yaml`](test/wokwi/template.test.yaml) = here you can set you test case, or as Woki would say, scenario to perform your test
    1. [`.github/workflows/ci.yaml`](.github/workflows/ci.yaml) = update the scenario name
1. Set your Wokwi token in your GitHub repository by setting it in secrets, as you can see in the following steps:
    1. Open **Setting** -> **Secrets and variables** -> **Actions**
    1. Create a **New repository secret**
    1. The name of the secret needs to be **`WOKWI_CLI_TOKEN`**, in the **Secret** section paste your token, and then click on **Add secret**

Congratulations! Now your repository is ready for your project and can perform Continuos Integration using GitHub Actions!

---

Please, feel free to improve this template by request something using an Issue or doing some Pull Request.
