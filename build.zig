const std = @import("std");

pub fn build(b: *std.Build) void {
    const target = b.standardTargetOptions(.{});
    const optimize = b.standardOptimizeOption(.{});

    const lib = b.addStaticLibrary(.{
        .name = "direct3d-headers",
        .target = target,
        .optimize = optimize,
        .root_source_file = b.addWriteFiles().add("empty.c", ""),
    });
    if (target.result.cpu.arch == .x86_64 and target.result.os.tag == .windows) {
        lib.addLibraryPath(b.path("x86_64"));
        lib.linkSystemLibrary("dxguid");
        lib.linkSystemLibrary("dxgi");
    }
    b.installArtifact(lib);

    lib.installHeadersDirectory(b.path("include"), ".", .{});
}

// TODO(build-system): this is needed because lib2.linkLibrary(lib)
// will not add the library path transitively to lib3.linkLibrary(lib2)
pub fn addLibraryPath(step: *std.Build.Step.Compile) void {
    step.addLibraryPath(.{ .cwd_relative = sdkPath("/x86_64") });
}

pub fn addLibraryPathToModule(module: *std.Build.Module) void {
    module.addLibraryPath(.{ .cwd_relative = sdkPath("/x86_64") });
}

fn sdkPath(comptime suffix: []const u8) []const u8 {
    if (suffix[0] != '/') @compileError("suffix must be an absolute path");
    return comptime blk: {
        const root_dir = std.fs.path.dirname(@src().file) orelse ".";
        break :blk root_dir ++ suffix;
    };
}
