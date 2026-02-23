
FROM gcc:13

WORKDIR /app

COPY . .
#compila y genera el server
RUN g++ -O2 -std=c++17 -pthread src/main.cpp -o server

ENV PORT=8080
EXPOSE 8080

CMD ["/app/server"]
