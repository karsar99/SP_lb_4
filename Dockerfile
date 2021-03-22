FROM amazonlinux:latest
RUN yum update -y && yum install gcc-c++ -y
COPY ./parent.cpp ./parent.cpp
COPY ./child.cpp ./child.cpp
RUN g++ child.cpp -o child
RUN g++ parent.cpp -o parent
CMD ./parent
