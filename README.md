<img width="60" align="left" alt="commision_unix" src="https://user-images.githubusercontent.com/65850970/234680595-0c2756d8-12ee-45e3-ae76-5100bc0156d4.png">

# mkhtml

mkhtml is an html document generator that works with gpt <br>
YouTube: https://youtu.be/ULvErLMKrTo

## Programming Language and Tools

Programming Language: C, Bash <br>
Compiler: GNU GCC <br>
Build Tool: CMake 

## Dependencies

Libcurl <br>
CMake (MIN 3.22)

## Installation

### Step 1: Download the Source codes

https://github.com/MertGunduz/mkhtml

### Step 2: Change permissions of INSTALL.sh

```sh
chmod 755 INSTALL.sh
```
running this command will change the permission of the INSTALL.sh

### Step 3: Run INSTALL.sh

```sh
./INSTALL.sh
```
running this bash file will build the application and create the folders.
##### Note: it can ask for sudo permission

### Step 4: Test Application

try running
```sh
mkhtml -h
```
if there are some output related to mkhtml then it means it is successfully builded

## How to use

### Generating HTML Files

```sh
mkhtml -G [DATA]
mkhtml --generate [DATA]
```
sends a request to openai api and generates the html file with the selected style

### Setting API Key

```sh
mkhtml -k [DATA]
mkhtml --key [DATA]
```
sets the openai api key 

### Setting CSS Style

```sh
mkhtml -c [CSS-DATA]
mkhtml --css [CSS-DATA]
```
sets the css style

### Outputting Website URL

```sh
mkhtml -w
mkhtml --website
```
outputs the website url

### Outputting Github URL

```sh
mkhtml -g
mkhtml --github
```
outputs the github url

### Outputting Configurations

```sh
mkhtml -s
mkhtml --settings
```
outputs the configurations 

### Outputting Version

```sh
mkhtml -v
mkhtml --version
```
outputs the mkhtml version

### Outputting Help Menu

```sh
mkhtml -h
mkhtml --help
```
outputs the help menu
