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
    if (lib.target.toTarget().cpu.arch == .x86_64) {
        lib.addLibraryPath("x86_64");
        lib.linkSystemLibraryName("dxguid");
        lib.linkSystemLibraryName("dxgi");
    }
    b.installArtifact(lib);

    lib.installHeadersDirectory("include", ".");
}

// TODO(build-system): this is needed because lib2.linkLibrary(lib)
// will not add the library path transitively to lib3.linkLibrary(lib2)
pub fn addLibraryPath(step: *std.build.CompileStep) void {
    step.addLibraryPath(sdkPath("/x86_64"));
}

fn sdkPath(comptime suffix: []const u8) []const u8 {
    if (suffix[0] != '/') @compileError("suffix must be an absolute path");
    return comptime blk: {
        const root_dir = std.fs.path.dirname(@src().file) orelse ".";
        break :blk root_dir ++ suffix;
    };
}
