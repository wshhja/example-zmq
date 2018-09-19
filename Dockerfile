FROM ubuntu:16.04
RUN apt-get update && \
    apt-get install git cmake gcc g++
RUN git clone https://github.com/zeromq/libzmq.git && \
    mkdir -p libzmq/build && cd libzmq/build && \
    cmake .. && make && make install && ldconfig

COPY run.sh /run.sh
RUN chmod a+x run.sh
