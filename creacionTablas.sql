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
	codigoCurso varchar(10) unique,
	periodo smallint unique,
	annio int not null unique,
	grupo int not null unique,
	profesorId bigint not null,
	cantEstudiantes int not null,
	constraint fkcurso foreign key(codigoCurso) references cursos(codigoCurso),
	constraint fkprofe foreign key(profesorId) references profesores(cedula)
	
)

create table reservacion(
	reservacionid serial primary key,
	horaInicio date not null,
	horaFin date not null,
	cursoxperiodo  bigint not null,
	aulaid varchar(10),
	constraint fkcursoxperiodo foreign key(cursoxperiodo) references cursosxperiodo(cursoxperiodoid),
	constraint fkaula foreign key(aulaid) references aulas(nombre)
)
