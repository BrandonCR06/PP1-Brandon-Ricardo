CREATE TABLE aulas (
	nombre varchar(10) PRIMARY KEY,
	capacidad int NOT NULL
)
CREATE TABLE cursos (
	codigoCurso varchar(10) primary key,
	codigoCarrera varchar(10),
	nombre VARCHAR ( 100 )  NOT NULL
)
CREATE TABLE profesores (
	cedula bigint PRIMARY KEY,
	nombre VARCHAR ( 100 )  NOT NULL
)
CREATE TABLE cursosxperiodo (
	cursoxperiodoid serial primary key,
	codigoCurso varchar(30) unique,
	periodo smallint,
	annio int not null unique,
	grupo int not null unique,
	profesorId bigint not null,
	cantEstudiantes int not null,
	constraint fkcurso foreign key(codigoCurso) references cursos(codigoCurso),
	constraint fkprofe foreign key(profesorId) references profesores(cedula)
	
)


create table reservacion(
	reservacionid serial  primary key,
	horaInicio time not null,
	horaFin  time not null,
	fecha date not null,
	cursoxperiodo  bigint not null,
	constraint fkcursoxperiodo foreign key(cursoxperiodo) references cursosxperiodo(cursoxperiodoid)
)

create table reservacionxaula  (
	reservacionxaulasid serial primary key,
	reservacionid int,
	aulaid varchar(10),
	constraint fkreservacion foreign key(reservacionid) references reservacion(reservacionid),
	constraint fkaula foreign key(aulaid) references aulas(nombre)
	
	
)

INSERT INTO cursos (codigocurso,codigocarrera,nombre) VALUES ('300','IC','Lenguajes');
INSERT INTO cursos (codigocurso,codigocarrera,nombre) VALUES ('421','IC','Bases');
INSERT INTO cursos (codigocurso,codigocarrera,nombre) VALUES ('182','IC','Requerimientos');
INSERT INTO cursos (codigocurso,codigocarrera,nombre) VALUES ('152','MA','Probabilidades');
INSERT INTO cursos (codigocurso,codigocarrera,nombre) VALUES ('226','CL','Comunicacion');

