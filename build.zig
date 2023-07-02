const std = @import("std");

pub fn build(b: *std.Build) void {
    const target = b.standardTargetOptions(.{});
    const optimize = b.standardOptimizeOption(.{});

    const lib = b.addStaticLibrary(.{
        .name = "direct3d-headers",
        .root_source_file = .{ .path = "stub.c" },
        .target = target,
        .optimize = optimize,
    });
    if (lib.target.toTarget().cpu.arch == .x86_64) lib.addLibraryPath("x86_64");
    b.installArtifact(lib);

    lib.installHeadersDirectory("include", ".");
}
