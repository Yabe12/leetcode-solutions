CREATE TABLE superadmin (
  username VARCHAR(50) PRIMARY KEY,
  password VARCHAR(50) NOT NULL
);

CREATE TABLE admin (
  id SERIAL PRIMARY KEY,
  username VARCHAR(50) NOT NULL,
  password VARCHAR(50) NOT NULL,
  superadmin_username VARCHAR(50),
  FOREIGN KEY (superadmin_username) REFERENCES superadmin(username)
);

CREATE TABLE student (
  id SERIAL PRIMARY KEY,
  name VARCHAR(50),
  student_id VARCHAR(20),
  gender VARCHAR(10),
  department VARCHAR(50),
  phone BIGINT,
  pcname VARCHAR(50),
  serial VARCHAR(50),
  superadmin_username VARCHAR(50),
  admin_id INT,
  FOREIGN KEY (superadmin_username) REFERENCES superadmin(username),
  FOREIGN KEY (admin_id) REFERENCES admin(id)
);

CREATE TABLE staff (
  id SERIAL PRIMARY KEY,
  name VARCHAR(50),
  staff_id VARCHAR(20),
  gender VARCHAR(10),
  job VARCHAR(50),
  phone BIGINT,
  typeofpc VARCHAR(20),
  pcname VARCHAR(50),
  serial VARCHAR(50),
  superadmin_username VARCHAR(50),
  admin_id INT,
  FOREIGN KEY (superadmin_username) REFERENCES superadmin(username),
  FOREIGN KEY (admin_id) REFERENCES admin(id)
);

CREATE TABLE nonstaff (
  id SERIAL PRIMARY KEY,
  name VARCHAR(50),
  nonstaff_id VARCHAR(20),
  gender VARCHAR(10),
  phone BIGINT,
  pcname VARCHAR(50),
  serial VARCHAR(50),
  superadmin_username VARCHAR(50),
  admin_id INT,
  FOREIGN KEY (superadmin_username) REFERENCES superadmin(username),
  FOREIGN KEY (admin_id) REFERENCES admin(id)
);