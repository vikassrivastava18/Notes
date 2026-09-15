## Useful Commands

### Copy command

`cp /mnt/c/Users/vikas/Downloads/support_key.pem .`

### File transfer (SCP)
`scp -i karma_new.pem -r karma-prod/ ubuntu@ec2-65-0-199-255.ap-south-1.compute.amazonaws.com:/var/www/`

### SSH
`ssh -i "karma_new.pem" ubuntu@ec2-65-0-199-255.ap-south-1.compute.amazonaws.com
`

## Docker 

### Concepts

- Docker image: A read-only template containing all the necessary files, libraries, and dependencies requires to run an app in a Docker container
- Docker container: A running instance of an image. That is, an executable package including the code, libraries, and dependencies needed to run the application.
- Dockerfile: A script containing instructions to create an image.

### Getting help
- docker --version

- docker info

- docker --help

-docker run --help

## Cheatsheet

### Building Images
Building an image with docker build 
`docker build`

Build an image without using the cache
`docker build --no-cache`

### Inspecting Containers
```
docker ps
docker ps --all
docker ps --filter 'name=red1'
docker logs frontend
```

### Running containers
```
# Run a container
docker run hello-world

# Run a container in the background
docker run --detach postgres

# Assign a name
docker run --name red1 redis
```

### Managing containers
```

```






