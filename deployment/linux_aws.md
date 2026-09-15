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

### Useful commands
```
# Run a command in Docker
docker compose exec backend python manage.py migrate

# Copy a database dump file
docker cp .\backend\tutor.dump myapp-db-1:/tmp/tutor.dump

# Restore the dump file into database
pg_restore -U postgres -h localhost -d myapp_production --clean --if-exists --no-owner myapp_dev.dump

# Check logs
docker compose logs db --tail=100

# Create and run a container from an image, with a custom name:
docker run --name <container_name> <image_name>

# Run a container with and publish a container’s port(s) to the host.
docker run -p <host_port>:<container_port> <image_name>

# Run a container in the background
docker run -d <image_name>

# Start or stop an existing container:
docker start|stop <container_name> (or <container-id>)

# Remove a stopped container:
docker rm <container_name>

# Open a shell inside a running container:
docker exec -it <container_name> sh

# Fetch and follow the logs of a container:
docker logs -f <container_name>

# To inspect a running container:
docker inspect <container_name> (or <container_id>)

# To list currently running containers:
docker ps
# List all docker containers (running and stopped):
docker ps --all

# View resource usage stats
docker container stats
```

### Managing containers
```

```







