FROM alpine:latest

RUN mkdir -p /lab
WORKDIR /lab

RUN apk update && apk add gcc musl-dev vim make

COPY . .
