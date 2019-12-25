# battle-simulator
### Run using Docker on Windows
Please install and configure vcxsrv: <br>
`choco install vcxsrv` <br>
Then build and run container: <br>
`docker build -t bs .` <br>
`set-variable -name DISPLAY -value [YOUR-IP]:0.0` <br>
`docker run -ti --rm -e DISPLAY=$DISPLAY bs` <br>
