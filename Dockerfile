# Builder
FROM ubuntu:24.04 AS builder

RUN apt-get update && apt-get install -y \
    g++ \
    cmake \
    make \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY . .

RUN mkdir build && cd build && cmake .. && make

# Production
FROM ubuntu:24.04

WORKDIR /app

COPY --from=builder /app/build/GraphEngine .

COPY --from=builder /app/examples ./examples

ENTRYPOINT ["./GraphEngine"]
