﻿// <auto-generated />
using Microsoft.EntityFrameworkCore;
using Microsoft.EntityFrameworkCore.Infrastructure;
using Microsoft.EntityFrameworkCore.Metadata;
using Microsoft.EntityFrameworkCore.Storage.ValueConversion;
using WT2._2.Models;

namespace WT2._2.Migrations
{
    [DbContext(typeof(DataBaseContext))]
    partial class DataBaseContextModelSnapshot : ModelSnapshot
    {
        protected override void BuildModel(ModelBuilder modelBuilder)
        {
#pragma warning disable 612, 618
            modelBuilder
                .HasAnnotation("Relational:MaxIdentifierLength", 128)
                .HasAnnotation("ProductVersion", "5.0.10")
                .HasAnnotation("SqlServer:ValueGenerationStrategy", SqlServerValueGenerationStrategy.IdentityColumn);

            modelBuilder.Entity("WT2._2.Models.Course", b =>
                {
                    b.Property<int>("Id")
                        .ValueGeneratedOnAdd()
                        .HasColumnType("int")
                        .HasAnnotation("SqlServer:ValueGenerationStrategy", SqlServerValueGenerationStrategy.IdentityColumn);

                    b.Property<int>("FacultyId")
                        .HasColumnType("int");

                    b.Property<string>("Name")
                        .HasColumnType("nvarchar(max)");

                    b.HasKey("Id");

                    b.HasIndex("FacultyId");

                    b.ToTable("Courses");

                    b.HasData(
                        new
                        {
                            Id = 1,
                            FacultyId = 1,
                            Name = "1"
                        },
                        new
                        {
                            Id = 2,
                            FacultyId = 2,
                            Name = "2"
                        },
                        new
                        {
                            Id = 3,
                            FacultyId = 1,
                            Name = "3"
                        },
                        new
                        {
                            Id = 4,
                            FacultyId = 3,
                            Name = "4s"
                        });
                });

            modelBuilder.Entity("WT2._2.Models.Faculty", b =>
                {
                    b.Property<int>("Id")
                        .ValueGeneratedOnAdd()
                        .HasColumnType("int")
                        .HasAnnotation("SqlServer:ValueGenerationStrategy", SqlServerValueGenerationStrategy.IdentityColumn);

                    b.Property<string>("Name")
                        .HasColumnType("nvarchar(max)");

                    b.HasKey("Id");

                    b.ToTable("Faculties");

                    b.HasData(
                        new
                        {
                            Id = 1,
                            Name = "ФЭИС"
                        },
                        new
                        {
                            Id = 2,
                            Name = "ЭФ"
                        },
                        new
                        {
                            Id = 3,
                            Name = "СФ"
                        },
                        new
                        {
                            Id = 4,
                            Name = "ФИСЭ"
                        });
                });

            modelBuilder.Entity("WT2._2.Models.Group", b =>
                {
                    b.Property<int>("Id")
                        .ValueGeneratedOnAdd()
                        .HasColumnType("int")
                        .HasAnnotation("SqlServer:ValueGenerationStrategy", SqlServerValueGenerationStrategy.IdentityColumn);

                    b.Property<int>("CourseId")
                        .HasColumnType("int");

                    b.Property<string>("Name")
                        .HasColumnType("nvarchar(max)");

                    b.HasKey("Id");

                    b.HasIndex("CourseId");

                    b.ToTable("Groups");

                    b.HasData(
                        new
                        {
                            Id = 1,
                            CourseId = 3,
                            Name = "ПО-4"
                        },
                        new
                        {
                            Id = 2,
                            CourseId = 3,
                            Name = "ПО-5"
                        },
                        new
                        {
                            Id = 3,
                            CourseId = 2,
                            Name = "Т-90"
                        },
                        new
                        {
                            Id = 4,
                            CourseId = 1,
                            Name = "Е-78"
                        },
                        new
                        {
                            Id = 5,
                            CourseId = 2,
                            Name = "ПГС-2"
                        },
                        new
                        {
                            Id = 6,
                            CourseId = 3,
                            Name = "ООО-ОАО"
                        });
                });

            modelBuilder.Entity("WT2._2.Models.Student", b =>
                {
                    b.Property<int>("Id")
                        .ValueGeneratedOnAdd()
                        .HasColumnType("int")
                        .HasAnnotation("SqlServer:ValueGenerationStrategy", SqlServerValueGenerationStrategy.IdentityColumn);

                    b.Property<int>("GroupId")
                        .HasColumnType("int");

                    b.Property<string>("Name")
                        .HasColumnType("nvarchar(max)");

                    b.HasKey("Id");

                    b.HasIndex("GroupId");

                    b.ToTable("Students");

                    b.HasData(
                        new
                        {
                            Id = 1,
                            GroupId = 1,
                            Name = "Макс"
                        },
                        new
                        {
                            Id = 2,
                            GroupId = 2,
                            Name = "Толя"
                        },
                        new
                        {
                            Id = 3,
                            GroupId = 1,
                            Name = "Ваня"
                        },
                        new
                        {
                            Id = 4,
                            GroupId = 3,
                            Name = "Петя"
                        },
                        new
                        {
                            Id = 5,
                            GroupId = 2,
                            Name = "Лёха"
                        });
                });

            modelBuilder.Entity("WT2._2.Models.Course", b =>
                {
                    b.HasOne("WT2._2.Models.Faculty", "Faculty")
                        .WithMany("Courses")
                        .HasForeignKey("FacultyId")
                        .OnDelete(DeleteBehavior.Cascade)
                        .IsRequired();

                    b.Navigation("Faculty");
                });

            modelBuilder.Entity("WT2._2.Models.Group", b =>
                {
                    b.HasOne("WT2._2.Models.Course", "Course")
                        .WithMany("Group")
                        .HasForeignKey("CourseId")
                        .OnDelete(DeleteBehavior.Cascade)
                        .IsRequired();

                    b.Navigation("Course");
                });

            modelBuilder.Entity("WT2._2.Models.Student", b =>
                {
                    b.HasOne("WT2._2.Models.Group", "Group")
                        .WithMany("Student")
                        .HasForeignKey("GroupId")
                        .OnDelete(DeleteBehavior.Cascade)
                        .IsRequired();

                    b.Navigation("Group");
                });

            modelBuilder.Entity("WT2._2.Models.Course", b =>
                {
                    b.Navigation("Group");
                });

            modelBuilder.Entity("WT2._2.Models.Faculty", b =>
                {
                    b.Navigation("Courses");
                });

            modelBuilder.Entity("WT2._2.Models.Group", b =>
                {
                    b.Navigation("Student");
                });
#pragma warning restore 612, 618
        }
    }
}
