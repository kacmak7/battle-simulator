FROM ubuntu:16.04
COPY . /app
WORKDIR /app
#RUN apt-get install -y software-properties-common && apt-get update
#RUN add-apt-repository -y ppa:ubuntu-toolchain-r/test
RUN apt-get update && apt-get install -y libstdc++6 gcc g++ build-essential libgles2-mesa-dev libsdl2-2.0-0 libsdl2-dev libsdl2-image-2.0-0
RUN apt-get dist-upgrade
RUN make
CMD /app/battle
