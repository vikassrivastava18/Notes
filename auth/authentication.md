## Authentication 
System needs to know that a user is one who they claim to be before getting access to resources.

### Basic Auth Methods

1. Basic - User sends username and password to auhtenticate themselves. They get a base64 encoded version of their credentials, which they can send through Authorization key in HTTP headers. Insecure!!

2. Digest authetication - Returns a MD5 hash version of credentials. Needs to be sent in every subsequent request in headers.

3. API key - Sent as X-API-KEY or Authorizatrion in header. Random strings do not save any user information unlike JWT.


### Session based
Stateful authentication, does not scale for large applications.
User send their credentials, servers saves the session ID and is sent to the client to be savesd as a session cookie and sent in every subsequent request. Redis is mostly used, in-memory or persistent memory also used.

### Token based

1. Bearer -  